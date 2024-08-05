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
#include "cores.h"

#define SUCESSO                           0
#define ALFABETO_INVALIDO                 1
#define ERRO_LEITURA_ARQUIVO              2
#define ERRO_CODIFICACAO                  3
#define ERRO_ABERTURA_ARQUIVO             4
#define NUM_ARG_INV                       5
#define MAX_TAMANHO_ARQUIVO               1024 
#define END_OF_STRING                     '\0'

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\nUso: %s <tipo-alfabeto> <entrada> <saida>\n", argv[0]);
        exit(NUM_ARG_INV);
    }

    char *verificacao;
    tipoAlfabetoBase64 alfabeto;
    alfabeto = (tipoAlfabetoBase64) strtoul(argv[1], &verificacao, 10);
    if (*verificacao != END_OF_STRING) {
        printf("%sAlfabeto invalido! Use '0' para Basico ou '1' para Seguro.%s\n", RED, RESET);
        return ALFABETO_INVALIDO;
    }
    if (alfabeto != padrao && alfabeto != seguro) {
        printf("\nAlfabeto invalido! Use '0' para Basico ou '1' para Seguro.\n");
        return ALFABETO_INVALIDO;
    }
    

    FILE *entrada = fopen(argv[2], "r");
    if (entrada == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n");
        return ERRO_ABERTURA_ARQUIVO;
    }

    byte bytes[MAX_TAMANHO_ARQUIVO];
    ull tamanhoArquivo = (ull) fread(bytes, 1, MAX_TAMANHO_ARQUIVO, entrada);
    fclose(entrada);

    char resultado[(tamanhoArquivo / 3) * 4];
    
    tipoErros erro = CodificarBase64(bytes, tamanhoArquivo, desabilitado, alfabeto, resultado);
    if (erro != ok) {
        printf("\nErro ao codificar: %d\n", erro);
        return ERRO_CODIFICACAO;
    }

    FILE *saida = fopen(argv[3], "w");
    if (saida == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n");
        return ERRO_ABERTURA_ARQUIVO;
    }

    fprintf(saida, "%s", resultado);
    fclose(saida);

    printf("\nArquivo codificado com sucesso.\n");
    return SUCESSO;
}
