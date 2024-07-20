
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



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include "cores.h"
#include "aula0701.h"

#define NUMERO_ARGUMENTOS											11 + NUMERO_MAXIMO_VERTICES * 2
#define SUCESSO																0
#define NUMERO_ARGUMENTOS_INVALIDO						1
#define ARGUMENTO_INVALIDO_NA_MATRIZ					3
#define ARGUMENTO_INVALIDO_NAS_DIMENSOES			4
#define BASE_INVALIDA													5
#define TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO			6
#define DIMENSAO_INVALIDA											7
#define MATRIZ_INVALIDA												8
#define NUMERO_NEGATIVO												9
#define END_OF_STRING '\0'

int main(int argc, char *argv[]) {
    useconds_t tempoCongelamento;
    us numeroLinhas, numeroColunas;
    float percentualDefeituosos, percentualApagados;
    char *verificacao;
    char *corFundo, *corAceso, *corDefeituoso, *corApagado;
    tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
		unsigned linhasVertices [NUMERO_MAXIMO_VERTICES];
		unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS];
		unsigned auxiliar,index, numeroVertices;

    if (argc > NUMERO_ARGUMENTOS) {
        printf("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <numero_vertices> <linha-vertice-1> <linha-vertice-2>... <linha-vertice-N> <coluna-vertice-1>...<coluna-vertice-N> <cor-fundo> <cor-aceso> <cor-apagado> <cor-defeituoso> \n", argv[0]);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    tempoCongelamento = (useconds_t)strtoul(argv[1], &verificacao, 10);
    if (*verificacao != END_OF_STRING) {
        printf("Argumento invalido: tempo de congelamento\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }

    numeroLinhas = (unsigned)strtoul(argv[2], &verificacao, 10);
    if (*verificacao != END_OF_STRING || numeroLinhas > NUMERO_MAXIMO_LINHAS) {
        printf("Argumento invalido: numero de linhas\n");
        exit(DIMENSAO_INVALIDA);
    }

    numeroColunas = (unsigned)strtoul(argv[3], &verificacao, 10);
    if (*verificacao != END_OF_STRING || numeroColunas > NUMERO_MAXIMO_COLUNAS) {
        printf("Argumento invalido: numero de colunas\n");
        exit(DIMENSAO_INVALIDA);
    }

    percentualDefeituosos = strtof(argv[4], &verificacao);
    if (*verificacao != END_OF_STRING || percentualDefeituosos < 0.0 || percentualDefeituosos > 100.0) {
        printf("Argumento invalido: percentual de defeituosos\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }

    percentualApagados = strtof(argv[5], &verificacao);
    if (*verificacao != END_OF_STRING || percentualApagados < 0.0 || percentualApagados > 100.0) {
        printf("Argumento invalido: percentual de apagados\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }

    numeroVertices = (unsigned)strtoul(argv[6], &verificacao,10);
    if (*verificacao != END_OF_STRING || percentualApagados < 0.0 || percentualApagados > 100.0) {
        printf("Argumento invalido: numero de vertices\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }
 
    
		corFundo = argv[7 + numeroVertices * 2];
    corAceso = argv[8 + numeroVertices * 2];
		corApagado = argv[9 + numeroVertices * 2];
    corDefeituoso = argv[10 + numeroVertices * 2];
		index = 7;

	printf("\nNum vertices: %u\n", numeroVertices);	
	usleep(3000000);
		for (auxiliar = 0; auxiliar < numeroVertices; auxiliar++){
			linhasVertices[auxiliar] = (unsigned) strtoul(argv[index + auxiliar], &verificacao, 10);
			colunasVertices[auxiliar] = (unsigned) strtoul(argv[index + numeroVertices + auxiliar], &verificacao,10);
		}


		for (auxiliar = 0; auxiliar < numeroVertices; auxiliar++){
			printf("\n (%u,%u)\n", linhasVertices[auxiliar], colunasVertices[auxiliar]);
		}




    tipoErros resultado = GerarDistribuicaoInicial(monitor, numeroLinhas, numeroColunas, percentualDefeituosos, percentualApagados);
    if (resultado != ok) {
        printf("Erro na geracao da distribuicao inicial: %d\n", resultado);
        exit(resultado);
    }

    MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas, corFundo, corApagado, corAceso, corDefeituoso);
		LimparMonitor(monitor, numeroLinhas, numeroColunas, corFundo, corApagado, corAceso, corDefeituoso);
		DesenharPoligono(monitor, numeroLinhas, numeroColunas, numeroVertices, linhasVertices, colunasVertices, corFundo, corApagado, corAceso, corDefeituoso);
		MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas, corFundo, corApagado, corAceso, corDefeituoso);
		return SUCESSO;
}



/* $RCSfile$ */
