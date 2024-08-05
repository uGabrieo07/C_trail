
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

#define SUCESSO										0
#define ALFABETO_INVALIDO					1
#define ERRO_DECODIFICACAO				2
#define END_OF_STRING							'\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
#include "aula0801.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("\n%sUso: %s <alfabeto> <codigo-base32>%s\n", RED, argv[0], RESET);
        return 1;
    }
		
		char *verificacao;
    tipoAlfabetoBase32 alfabeto = (tipoAlfabetoBase32) strtoul(argv[1], &verificacao, 10);
  
		if (*verificacao != END_OF_STRING)	{
        printf("\n%sAlfabeto invalido! Use '0' ou '1'.%s\n", RED, RESET);
        exit(ALFABETO_INVALIDO);
    }

    char *string = argv[2];
    byte bytes[MAX_NUMERO_BYTES];
		ull numBytes;
    tipoErros resultado = DecodificarBase32(string, bytes, &numBytes, alfabeto);
		
    if (resultado != ok) {
        printf("\n%sErro: %d%s\n", RED, resultado, RESET);
        exit(ERRO_DECODIFICACAO);
    }
		
		us auxiliar;
    printf("%s>>>>> %s", BOLD_BLACK, RESET);
    for ( auxiliar = 0; auxiliar < numBytes; auxiliar++) {
        printf("%s%02X%s ", GREEN, bytes[auxiliar], RESET);
    }
    printf("\n");

    return 0;
}

/* $RCSfile$ */
