
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

#define NUMERO_ARGUMENTOS											14
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
    us numeroLinhas, numeroColunas, linhaA, colunaA, linhaB, colunaB;
    float percentualDefeituosos, percentualApagados;
    char *verificacao;
    char *corFundo, *corAceso, *corDefeituoso, *corApagado;
    tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

    if (argc != NUMERO_ARGUMENTOS) {
        printf("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <linhaA> <colunaA> <linhaB> <colunaB> <cor-fundo> <cor-aceso> <cor-apagado> <cor-defeituoso> \n", argv[0]);
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

	
    linhaA = strtof(argv[6], &verificacao);
    if (*verificacao != END_OF_STRING || percentualApagados < 0.0 || percentualApagados > 100.0) {
        printf("Argumento invalido: linhaA\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }


    colunaA = strtof(argv[7], &verificacao);
    if (*verificacao != END_OF_STRING || percentualApagados < 0.0 || percentualApagados > 100.0) {
        printf("Argumento invalido: colunaA\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }


    linhaB = strtof(argv[8], &verificacao);
    if (*verificacao != END_OF_STRING || percentualApagados < 0.0 || percentualApagados > 100.0) {
        printf("Argumento invalido: linhaB\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }


    colunaB= strtof(argv[9], &verificacao);
    if (*verificacao != END_OF_STRING || percentualApagados < 0.0 || percentualApagados > 100.0) {
        printf("Argumento invalido: colunaB\n");
        exit(ARGUMENTO_INVALIDO_NAS_DIMENSOES);
    }
    
		corFundo = argv[10];
    corAceso = argv[11];
		corApagado = argv[12];
    corDefeituoso = argv[13];

    tipoErros resultado = GerarDistribuicaoInicial(monitor, numeroLinhas, numeroColunas, percentualDefeituosos, percentualApagados);
    if (resultado != ok) {
        printf("Erro na geracao da distribuicao inicial: %d\n", resultado);
        exit(resultado);
    }

    MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas, corFundo, corApagado, corAceso, corDefeituoso);
		LimparMonitor(monitor, numeroLinhas, numeroColunas, corFundo, corApagado, corAceso, corDefeituoso);
		DesenharReta(monitor, numeroLinhas, numeroColunas, linhaA, colunaA, linhaB, colunaB, corFundo, corApagado, corAceso, corDefeituoso);
    MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas, corFundo, corApagado, corAceso, corDefeituoso);
    
		return SUCESSO;
}



/* $RCSfile$ */
