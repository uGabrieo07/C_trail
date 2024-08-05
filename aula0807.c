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

#define SUCESSO																0
#define ALFABETO_INVALIDO											1
#define ERRO_DECODIFICACAO										2
#define FINAL_LINHA_INVALIDO									3
#define NUM_ARG_INVALIDO											4
#define END_OF_STRING                         '\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
#include "aula0801.h"

int main(int argc, char *argv[]) {

		char *verificacao;
		
    if (argc != 4) {
        printf("\n%sUso: %s <alfabeto> <final_linha> <codigo-base64>%s\n", RED, argv[0], RESET);
        exit(NUM_ARG_INVALIDO);
    }

    tipoAlfabetoBase64 alfabeto = (tipoAlfabetoBase64) strtoul(argv[1], &verificacao, 10);

    if (*verificacao != END_OF_STRING) {
        printf("\n%sAlfabeto invalido! Use '0' ou '1'.%s\n", RED, RESET);
        exit(ALFABETO_INVALIDO);
    }
		
		
    tipoFinalLinha finalLinha = (tipoFinalLinha) strtoul(argv[2], &verificacao, 10);

    char *string = argv[3];
    byte bytes[MAX_NUMERO_BYTES];
    ull numBytes;
    tipoErros resultado = DecodificarBase64(string, finalLinha, alfabeto, bytes, &numBytes);

    if (resultado != ok) {
        printf("\n%sErro: %d%s\n", RED, resultado, RESET);
        exit(ERRO_DECODIFICACAO);
    }

    us auxiliar;
    printf("%s>>>>> %s", BOLD_BLACK, RESET);
    for (auxiliar = 0; auxiliar < numBytes; auxiliar++) {
        printf("%s%02X%s ", GREEN, bytes[auxiliar], RESET);
    }
    printf("\n");

    return 0;
}

/* $RCSfile$ */
