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
#include <string.h>
#include "aula0801.h"

#define SUCESSO                           0
#define ALFABETO_INVALIDO                 1
#define ERRO_LEITURA_ARQUIVO              2
#define ERRO_DECODIFICACAO                3
#define ERRO_ABERTURA_ARQUIVO             4
#define NUM_ARG_INV                       5
#define MAX_TAMANHO_ARQUIVO               1024 

int 
main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\nUso: %s <tipo-alfabeto> <entrada> <saida>\n", argv[0]);
        exit(NUM_ARG_INV);
    }

    tipoAlfabetoBase64 alfabeto;
    alfabeto = (tipoAlfabetoBase64) strtoul(argv[1], NULL, 10);
    if (alfabeto != padrao && alfabeto != seguro) {
        printf("\nAlfabeto invalido! Use '0' para Basico ou '1' para Seguro.\n");
        return ALFABETO_INVALIDO;
    }

    FILE *entrada = fopen(argv[2], "r");
    if (entrada == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n");
        return ERRO_ABERTURA_ARQUIVO;
    }

    char bytes[MAX_TAMANHO_ARQUIVO];
    size_t tamanhoArquivo = fread(bytes, 1, MAX_TAMANHO_ARQUIVO, entrada);
    fclose(entrada);
    bytes[tamanhoArquivo] = '\0';

    byte resultado[((MAX_TAMANHO_ARQUIVO / 4) * 3) + 1];
    
    ull numBytes;
    tipoErros erro = DecodificarBase64(bytes, desabilitado, alfabeto, resultado, &numBytes);
    if (erro != ok) {
        printf("\nErro ao decodificar: %d\n", erro);
        return ERRO_DECODIFICACAO;
    }

    FILE *saida = fopen(argv[3], "w");
    if (saida == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n");
        return ERRO_ABERTURA_ARQUIVO;
    }

    fwrite(resultado, 1, numBytes, saida);
    fclose(saida);

    printf("\nArquivo decodificado com sucesso.\n");
    return SUCESSO;
}
