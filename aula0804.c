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
#include "cores.h" 
#include "aula0801.h" 

#define SUCESSO 0
#define NUMERO_BYTES_INVALIDO 1
#define NUMERO_ARGUMENTOS_INVALIDO 2
#define ARGUMENTO_INVALIDO_NOS_BYTES 3
#define BASE_INVALIDA 4
#define VALOR_INVALIDO 5
#define BYTE_NEGATIVO 6
#define NUMERO_BYTES_NEGATIVO 7
#define ERRO_CODIFICACAO 8
#define TIPO_ALF_INVALIDO 9
#define END_OF_STRING '\0'

int main(int argc, char *argv[]) {
    ull auxiliar;
    tipoErros resultado;
    ull numeroBytes;
    char *verificacao;
    tipoAlfabetoBase32 tipoAlfabeto;


    if (argv[2][0] == '-') {
        printf("%sO numero de bytes nao pode ser negativo%s\n", RED, RESET);
        exit(NUMERO_BYTES_NEGATIVO);
    }

    numeroBytes = (ull) strtoul(argv[2], &verificacao, 10);
    if (*verificacao != END_OF_STRING) {
        printf("%sNumero de bytes invalido%s\n", RED, RESET);
        exit(NUMERO_BYTES_INVALIDO);
    }

    if (argc != numeroBytes + 3) {
        printf("%sUso: %s <tipo-alfabeto> <numero-de-bytes> <byte-1> <byte-2> ... <byte-N>\n%s", RED, argv[0], RESET);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    tipoAlfabeto = (tipoAlfabetoBase32) strtoul(argv[1], &verificacao, 10);
    if (*verificacao != END_OF_STRING) {
        printf("%sTipo de alfabeto base 32 invalido%s\n", RED, RESET);
        exit(TIPO_ALF_INVALIDO);
    }

    byte bytes[numeroBytes];
    char string[64]; 

    for (auxiliar = 0; auxiliar < numeroBytes; auxiliar++) {
        if (argv[auxiliar + 3][0] == '-') {
            printf("%sOs bytes devem ser numeros positivos%s\n", RED, RESET);
            exit(BYTE_NEGATIVO);
        }

        bytes[auxiliar] = (byte) strtoul(argv[auxiliar + 3], &verificacao,16);

        if (*verificacao != END_OF_STRING) {
            printf("%sArgumento invalido: byte\n%s", RED, RESET);
            exit(ARGUMENTO_INVALIDO_NOS_BYTES);
        }
    }

    resultado = CodificarBase32(bytes, numeroBytes, tipoAlfabeto, string);

    if (resultado != ok) {
        printf("%sAlgo deu errado na codificacao para a base 32%s\n", RED, RESET);
        exit(ERRO_CODIFICACAO);
    }

    printf("%s>>>>>%s %s%s%s\n", BOLD_BLACK, RESET, GREEN, string, RESET);

    return SUCESSO;
}

/* $RCSfile$ */
