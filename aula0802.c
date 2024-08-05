#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "cores.h"
#include "aula0801.h"

#define NUMERO_ARGUMENTOS 14
#define SUCESSO 0
#define NUMERO_BYTES_INVALIDO 1
#define NUMERO_ARGUMENTOS_INVALIDO 2
#define ARGUMENTO_INVALIDO_NOS_BYTES 3
#define BASE_INVALIDA 4
#define VALOR_INVALIDO 5
#define BYTE_NEGATIVO 6
#define NUMERO_BYTES_NEGATIVO 7
#define ERRO_CODIFICACAO 8
#define END_OF_STRING '\0'

int main(int argc, char *argv[]) {
    us auxiliar, resultado;
    ull numeroBytes;
    char *verificacao;

    if (argv[1][0] == '-') {
        printf("%sO numero de bytes nao pode ser negativo%s\n", RED, RESET);
        exit(NUMERO_BYTES_NEGATIVO);
    }

    numeroBytes = (ull) strtoul(argv[1], &verificacao, 10);
    if (*verificacao != END_OF_STRING) {
        printf("%sNumero de bytes invalido%s\n", RED, RESET);
        exit(NUMERO_BYTES_INVALIDO);
    }

    if (argc != numeroBytes + 2) {
        printf("%sUso: %s<numero-de-bytes> <byte-1> <byte-2> <byte-3> ... <byte-N>\n%s", RED, argv[0], RESET);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    byte bytes[numeroBytes];
		char string[numeroBytes];
    for (auxiliar = 0; auxiliar < numeroBytes; auxiliar++) {
        if (argv[auxiliar + 2][0] == '-') {
            printf("%sOs bytes devem ser numero positivos%s\n", RED, RESET);
            exit(BYTE_NEGATIVO);
        }

        bytes[auxiliar] = (byte) strtoul(argv[auxiliar + 2], &verificacao, 10);

        if (*verificacao != END_OF_STRING) {
            printf("Argumento invalido: bytes\n");
            exit(ARGUMENTO_INVALIDO_NOS_BYTES);
        }
    }

    if (errno == EINVAL) {
        printf("%sBase invalida%s\n", RED, RESET);
        exit(BASE_INVALIDA);
    }

    if (errno == ERANGE) {
        printf("%sValor maximo do argumento foi ultrapassado%s\n", RED, RESET);
        exit(VALOR_INVALIDO);
    }


    resultado = CodificarBase16(bytes, numeroBytes, string);

    if (resultado != ok) {
        printf("%sAlgo deu errado na codificacao para a base 16%s\n", RED, RESET);
        exit(ERRO_CODIFICACAO);
    }

    printf("%s%s>>>>>%s %s%s%s%s\n", WHITE_BACKGROUND, BOLD_BLACK, RESET, WHITE_BACKGROUND, GREEN, string, RESET);

    return SUCESSO;
}
