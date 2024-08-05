
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao:
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif
 
#ifdef __linux__
#define _XOPEN_SOURCE 600   
#endif


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "aula0701.h"
#include "aula0101.h"
#include "cores.h"


char * 
ObterCodigoAnsiCor(char *nomeCor, tipoFundoTexto fundoTexto) {
    if (nomeCor == NULL) {
        return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
    }

    if (fundoTexto == fundo) {
        if (strcmp(nomeCor, "preto") == 0) return BLACK_BACKGROUND;
        if (strcmp(nomeCor, "vermelho") == 0) return RED_BACKGROUND;
        if (strcmp(nomeCor, "verde") == 0) return GREEN_BACKGROUND;
        if (strcmp(nomeCor, "amarelo") == 0) return YELLOW_BACKGROUND;
        if (strcmp(nomeCor, "azul") == 0) return BLUE_BACKGROUND;
        if (strcmp(nomeCor, "magenta") == 0) return MAGENTA_BACKGROUND;
        if (strcmp(nomeCor, "ciano") == 0) return CYAN_BACKGROUND;
        if (strcmp(nomeCor, "branco") == 0) return WHITE_BACKGROUND;
    } else {
        if (strcmp(nomeCor, "preto") == 0) return BLACK;
        if (strcmp(nomeCor, "vermelho") == 0) return RED;
        if (strcmp(nomeCor, "verde") == 0) return GREEN;
        if (strcmp(nomeCor, "amarelo") == 0) return YELLOW;
        if (strcmp(nomeCor, "azul") == 0) return BLUE;
        if (strcmp(nomeCor, "magenta") == 0) return MAGENTA;
        if (strcmp(nomeCor, "ciano") == 0) return CYAN;
        if (strcmp(nomeCor, "branco") == 0) return WHITE;
    }

  
    return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
}


tipoErros 
MostrarMonitor(
    useconds_t tempoEspera,
    tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
    unsigned numeroLinhas,
    unsigned numeroColunas,
    char *corFundo,
    char *corPixelApagado,
    char *corPixelAceso,
    char *corPixelDefeituoso
) {
		us linha;
		us coluna;
		char monitorMostrado[numeroLinhas][numeroColunas];	
		system("clear");		

    if (corFundo == corPixelApagado || corFundo == corPixelAceso || corFundo == corPixelDefeituoso) {
        return coresIguais;
    }

    for (linha = 0; linha < numeroLinhas; linha++) {
        for (coluna = 0; coluna < numeroColunas; coluna++) {
            if (linha == 0 || linha == numeroLinhas - 1){
							monitorMostrado[linha][coluna] = '-';
            }
						else if ((coluna == 0 && linha != 0 && linha != numeroLinhas - 1) || (coluna == numeroColunas - 1 && linha != 0 && linha != numeroLinhas -1 )){
							monitorMostrado[linha][coluna] = '|';
						}
					
						else if (linha != 0 && linha != numeroLinhas - 1 && coluna != 0){
							switch (monitor[linha][coluna]){
								case apagado:
									monitorMostrado[linha][coluna] = apagado;
									break;
								case aceso:
									monitorMostrado[linha][coluna] = aceso;
									break;
								case defeituoso:
									monitorMostrado[linha][coluna] = defeituoso;	
									break;
								default:
									monitorMostrado[linha][coluna] = ' ';
									break;
							}
						}  
        }
				printf("\n");
    }
		
		printf("\n\n");

		for (linha = 0; linha < numeroLinhas; ++linha){ 
      for (coluna = 0; coluna < numeroColunas; ++coluna){
        if (monitorMostrado[linha][coluna] == apagado){
					printf("%s%c%s", ObterCodigoAnsiCor(corPixelApagado, fundo), APAGADO, RESET);
				}
				else if (monitorMostrado[linha][coluna] == aceso){
					printf("%s%c%s", ObterCodigoAnsiCor(corPixelAceso, fundo), ACESO, RESET);
				}
				else if (monitorMostrado[linha][coluna] == defeituoso){
					printf("%s%s%c%s%s%s", ObterCodigoAnsiCor(corFundo, fundo), ObterCodigoAnsiCor(corPixelDefeituoso, texto), DEFEITUOSO, ObterCodigoAnsiCor(corFundo, fundo), ObterCodigoAnsiCor(corPixelDefeituoso, texto), RESET);
				}
				else if (monitorMostrado[linha][coluna] == ' '){
					printf("%s%c%s", ObterCodigoAnsiCor(corFundo, fundo), ' ', RESET);
				}
				else{
					printf("%c",monitorMostrado[linha][coluna]);
				}
			}
			printf("\n");
		}

		printf("\n\n");
    usleep(tempoEspera);

    return ok;
}



tipoErros 
GerarDistribuicaoInicial(
    tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
    unsigned numeroLinhas,
    unsigned numeroColunas,
    float percentualDefeituosos,
    float percentualApagados
) {
    if (percentualDefeituosos < 0 || percentualDefeituosos > 100 || percentualApagados < 0 || percentualApagados > 100) {
        return percentualInvalido;
    }

    srand(time(NULL));

    unsigned  totalPixels = numeroLinhas * numeroColunas;
    unsigned numDefeituosos = (unsigned)((percentualDefeituosos / 100.0) * totalPixels);
    unsigned numApagados = (unsigned)((percentualApagados / 100.0) * totalPixels);
    unsigned numAcesos = totalPixels - numDefeituosos - numApagados;
		us linha, coluna, numAuxiliar;
	
		printf("\nnumApagados:%u \n", numApagados);
		printf("\nnumDefeituosos:%u \n", numDefeituosos);
		printf("\nnumAcesos:%u \n", numAcesos);

		/* incia a matriz com todos os pixels apagados */
    for (linha = 0; linha < numeroLinhas; linha++) {
        for (coluna = 0; coluna < numeroColunas; coluna++) {
            monitor[linha][coluna] = apagado;
        }
    }
	printf("\nInciou a matriz com pixels apagados\n");	
		if (numDefeituosos != 0){
		/* Preencher pixels defeituosos aleatoriamente */
    for (numAuxiliar= 0; numAuxiliar <= numDefeituosos; numAuxiliar++) {
        do {
            linha = rand() % numeroLinhas;
            coluna = rand() % numeroColunas;
        } while (monitor[linha][coluna] != apagado);
        monitor[linha][coluna] = defeituoso;
    }
		}
	printf("\nPosicionou os pixel defeituosos\n");
    /* Preencher pixels acesos aleatoriamente */
    for (numAuxiliar = 0; numAuxiliar < numAcesos; numAuxiliar++) {
        do {
            linha = rand() % numeroLinhas;
            coluna = rand() % numeroColunas;
        } while (monitor[linha][coluna] != apagado);
        monitor[linha][coluna] = aceso;
		}
	printf("\nPreencheu com os pixel acesos\n");
    return ok;
}

tipoErros
LimparMonitor (
							tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
							unsigned numeroLinhas,
							unsigned numeroColunas, 
							char * corFundo,
							char *corPixelApagado,
							char *corPixelAceso,
							char *corPixelDefeituoso){

		us linha, coluna;
	
    for (linha = 0; linha < numeroLinhas; linha++) {
        for (coluna = 0; coluna < numeroColunas; coluna++) {
					if (monitor[linha][coluna] != defeituoso){
            monitor[linha][coluna] = apagado;
					}
					else{
						continue;
					}
        }

		}	
		
		return ok;
}


tipoErros
DesenharReta (
						tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS], /* E/S */
						unsigned numeroLinhas, /* E */
						unsigned numeroColunas, /* E */
						unsigned linhaA, /* E */
						unsigned colunaA, /* E */
						unsigned linhaB, /* E */
						unsigned colunaB, /* E */
					  char *corFundo, /* E */
						char *corPixelApagado, /* E */
						char *corPixelAceso, /* E */
						char *corPixelDefeituoso /* E */){


		/*Equacao de reta: y = yo + (y1-yo)/(x1-xo) X (x-xo)*/


		int varX, varY, passos, numeroAuxiliar;
		float xIncremento, yIncremento, x, y;
		
		if (linhaA >= numeroLinhas || linhaB >= numeroLinhas || colunaA >= numeroColunas || colunaB >= numeroColunas)
        return dimensaoInvalida;

    varX = (int)colunaB - (int)colunaA;
    varY = (int)linhaB - (int)linhaA;
    passos = abs(varX) > abs(varY) ? abs(varX) : abs(varY);
    xIncremento = varX / (float) passos;
    yIncremento = varY / (float) passos;


    x = colunaA;
    y = linhaA;


    for (numeroAuxiliar = 0; numeroAuxiliar <= passos; numeroAuxiliar++) {
        monitor[(unsigned) round(y)][(unsigned) round(x)] = aceso;
        x += xIncremento;
        y += yIncremento;
    }

    return ok;
}


tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                  unsigned numeroLinhas,
                  unsigned numeroColunas,
                  unsigned numeroVertices,
                  unsigned linhasVertices [NUMERO_MAXIMO_VERTICES],
                  unsigned colunasVertices [NUMERO_MAXIMO_VERTICES],
                  char *corFundo,
                  char *corPixelApagado,
                  char *corPixelAceso,
	                char *corPixelDefeituoso) {

  
		
		if (numeroVertices < 3) {
        return coordForaLimits;
    }

		unsigned auxiliar, linhaA, colunaA, linhaB, colunaB;
    
		for (auxiliar = 0; auxiliar < numeroVertices - 1; auxiliar++) {
        linhaA = linhasVertices[auxiliar];
        colunaA = colunasVertices[auxiliar];
        linhaB = linhasVertices[auxiliar + 1];
        colunaB = colunasVertices[auxiliar + 1];
		
        if (linhaA >= numeroLinhas || colunaA >= numeroColunas || linhaB >= numeroLinhas || colunaB >= numeroColunas) {
            return coordForaLimits;
        }


        DesenharReta(monitor, numeroLinhas, numeroColunas, linhaA, colunaA, linhaB, colunaB, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso);
		}

    linhaA = linhasVertices[numeroVertices - 1];
	  colunaA = colunasVertices[numeroVertices - 1];
    linhaB = linhasVertices[0];
    colunaB = colunasVertices[0];

    if (linhaA >= numeroLinhas || colunaA >= numeroColunas || linhaB >= numeroLinhas || colunaB >= numeroColunas) {
        return coordForaLimits;
    }

    DesenharReta(monitor, numeroLinhas, numeroColunas, linhaA, colunaA, linhaB, colunaB, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso); 
		
		return ok;
}
	


tipoErros 
PreencherPoligono(
									useconds_t tempoEspera,
                  tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
                  unsigned numeroLinhas, 
                  unsigned numeroColunas,
									unsigned linha,
									unsigned coluna, 
                  unsigned numeroVertices, 
                  unsigned *linhasVertices[NUMERO_MAXIMO_VERTICES], 
                  unsigned *colunasVertices[NUMERO_MAXIMO_VERTICES], 
                  char *corFundo, 
                  char *corApagado, 
                  char *corAceso, 
                  char *corDefeituoso) {
                  
    
    unsigned maiorLinha, maiorColuna, menorLinha, menorColuna, linhaAtual, colunaAtual, auxiliar, i, j;
    
    maiorLinha = *(linhasVertices[0]);
    maiorColuna = *(colunasVertices[0]);
    menorLinha = *(linhasVertices[0]);
    menorColuna = *(colunasVertices[0]);
    
    for (auxiliar = 1; auxiliar < numeroVertices; auxiliar++){
      linhaAtual = *(linhasVertices[auxiliar]);
      colunaAtual = *(colunasVertices[auxiliar]);
      
      if (linhaAtual > maiorLinha){
        maiorLinha = linhaAtual;
      } 
        
      else if (colunaAtual > maiorColuna){
        maiorColuna = colunaAtual;
      }
      
      else{
        continue;  
      }
      
    }
    
    for (auxiliar = 1; auxiliar < numeroVertices; auxiliar++){
      linhaAtual = linhasVertices[auxiliar];
      colunaAtual = colunasVertices[auxiliar];
      
      if (linhaAtual < menorLinha){
        menorLinha = linhaAtual;
      } 
        
      else if (colunaAtual < menorColuna){
        menorColuna = colunaAtual;
      }
      
      else{
        continue;  
      }
        
    }
    
    
    for (i = 1; i <= numeroLinhas; i++){
      for (j = 1; j <= numeroColunas; j++){
        
        if (linha >= menorLinha && linha <= maiorLinha && coluna >= menorColuna && coluna <= maiorColuna && monitor[linha][coluna] == apagado){
          
          monitor[linha][coluna] = aceso;
        
        }
       
				else if (monitor[linha][coluna] == defeituoso){
					return pixelDefeituoso;
				
				}
 
        else{
          continue;
        }
      }
    
    }
    

    return ok;
}







/* $RCSfile$ */
