
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
#define _XOPEN_SOURCE 700
#endif
 
#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif


#ifndef _AULA0701_
#include <unistd.h>
#define _AULA0701_ "@(#)aula0701.h $Revision$"
#define NUMERO_MAXIMO_LINHAS										250
#define NUMERO_MAXIMO_COLUNAS										800
#define NUMERO_MAXIMO_VERTICES									50
#define APAGADO																	' '
#define ACESO																		' '
#define DEFEITUOSO															'.'

typedef unsigned short us; 

typedef enum  {
			fundo = 0, 
			texto = 1
} tipoFundoTexto;

typedef enum {
			 defeituoso = -1,
			 apagado = 0,
			 aceso = 1
} tipoPixel;

typedef enum {
			ok = 0,
			coresIguais = 1,
			percentualInvalido = 2,
			corNaoEncontrada = 3,
			coordForaLimits = 4,
			pixelDefeituosoReta = 5,
			dimensaoInvalida = 6,
			erroDesenharReta = 7,
			numVerticesInv = 8,
			pixelDefeituoso = 9
} tipoErros;

char *
ObterCodigoAnsiCor (char *nomeCor, tipoFundoTexto fundoTexto);

tipoErros
MostrarMonitor (
								useconds_t tempoEspera,
								tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
								unsigned numeroLinhas,
								unsigned numeroColunas,
								char *corFundo,
								char *corPixelApagado,
								char *corPixelAceso,
								char *corPixelDefeituoso);

tipoErros 
GerarDistribuicaoInicial(
													tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
													unsigned numeroLinhas,
													unsigned numeroColunas, 
													float percentualDefeituosos, 
													float percentualApagados);

tipoErros
LimparMonitor (
							tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
							unsigned numeroLinhas,
							unsigned numeroColunas,
							char * corFundo,
							char *corPixelApagado,
							char *corPixelAceso,
							char *corPixelDefeituoso);
									
tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS], /* E/S */
							unsigned numeroLinhas, /* E */	
							unsigned numeroColunas, /* E */
							unsigned linhaA, /* E */
							unsigned colunaA, /* E */
							unsigned linhaB, /* E */
							unsigned colunaB, /* E */
							char *corFundo, /* E */
							char *corPixelApagado, /* E */
							char *corPixelAceso, /* E */
							char *corPixelDefeituoso /* E */);

tipoErros
DesenharPoligono (
									tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS], /* E/S */
									unsigned numeroLinhas, /* E*/
									unsigned numeroColunas, /* E */
									unsigned numeroVertices, /* E */
									unsigned linhasVertices [NUMERO_MAXIMO_VERTICES], /* E */
									unsigned colunasVertices [NUMERO_MAXIMO_VERTICES], /* E */
									char *corFundo, /* E */
									char *corPixelApagado, /* E */
									char *corPixelAceso, /* E */
									char *corPixelDefeituoso /* E */);


tipoErros
PreencherPoligono (useconds_t tempoEspera, /* E */
 tipoPixel monitor[NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],/* E/S */
 unsigned numeroLinhas, /* E */
 unsigned numeroColunas,
 unsigned linha,
 unsigned coluna,
 unsigned numeroVertices,
 unsigned *linhasVertices[NUMERO_MAXIMO_VERTICES], /* E */
 unsigned *colunasVertices[NUMERO_MAXIMO_VERTICES], /* E */
 char *corFundo, /* E */
 char *corPixelApagado, /* E */
 char *corPixelAceso, /* E */
 char *corPixelDefeituoso /* E */);
#endif































/* $RCSfile$ */
