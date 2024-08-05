#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cores.h"
#include "aula0801.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define CARACTERE_INVALIDO 3
#define ERRO_DECODIFICACAO 4 
#define END_OF_STRING '\0'

int main(int argc, char *argv[]) {
    us auxiliar;
    tipoErros resultado;

    if (argc != 2) {
        printf("%sUso: %s<string-a-ser-decodificada>%s\n", RED, argv[0], RESET);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    if (strlen(argv[1]) % 2 != 0) {
        printf("%sA string deve ter um comprimento par%s\n", RED, RESET);
        exit(CARACTERE_INVALIDO);
    }

    ull *numeroBytes = (ull) strlen(argv[1]) / 2;
    if (*numeroBytes > MAX_NUMERO_BYTES) {
        printf("%sA string ultrapassa o numero maximo de bytes permitido%s\n", RED, RESET);
        exit(ARGUMENTO_INVALIDO);
    }

    byte bytes[*numeroBytes];
    resultado = DecodificarBase16(argv[1], bytes, numeroBytes);

    if (resultado != ok) {
        switch (resultado) {
            case comprimentoInvalido:
                printf("%sComprimento da string invalido%s\n", RED, RESET);
                break;
            case caractereInvalido:
                printf("%sCaractere invalido na string%s\n", RED, RESET);
                break;
            default:
                printf("%sErro desconhecido na decodificacao%s\n", RED, RESET);
                break;
        }
        exit(ERRO_DECODIFICACAO);
    }

    for (auxiliar = 0; auxiliar < *numeroBytes; auxiliar++) {
        printf("%03u ", bytes[auxiliar]);
    }
    printf("\n");

    return SUCESSO;
}
