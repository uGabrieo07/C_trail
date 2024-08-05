
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
#define ERRO_CODIFICACAO  				2
#define NUM_ARGUMENTOS_INVALIDO		3
#define FINAL_LINHA_INVALIDO			4
#define END_OF_STRING							'\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
#include "aula0801.h"

int main(int argc, char *argv[]) {
		
		char *verificacao;
    tipoAlfabetoBase64 alfabeto = (tipoAlfabetoBase64) strtoul(argv[1], &verificacao, 10);
  
		if (*verificacao != END_OF_STRING)	{
        printf("\n%sAlfabeto invalido! Use '0' ou '1'.%s\n", RED, RESET);
        exit(ALFABETO_INVALIDO);
    }
		
		tipoFinalLinha finalLinha = (tipoFinalLinha) strtoul(argv[2], &verificacao, 10);

		if (*verificacao != END_OF_STRING){
			printf("\n%sOpcao final de linha invalida! Use '0' ou '1'.%s\n", RED, RESET);
			exit(FINAL_LINHA_INVALIDO);
		}
   
  
    us auxiliar;
    byte bytes[MAX_NUMERO_BYTES];
    ull numBytes = (ull) strtoul(argv[3], &verificacao, 10);

		
    if (argc != numBytes + 4 ) {
        printf("\n%sUso: %s <alfabeto> <flinha> <numero-bytes> <codigo-hexadecimal>%s\n", RED, argv[0], RESET);
        exit(NUM_ARGUMENTOS_INVALIDO);
    }

    for (auxiliar = 0; auxiliar < numBytes; auxiliar++) {
       bytes[auxiliar] = (byte) strtoul(argv[auxiliar + 4], &verificacao,16);
		}
    
    char string[64];

    tipoErros resultado = CodificarBase64(bytes, numBytes, finalLinha, alfabeto, string);
		
    if (resultado != ok) {
        printf("\n%sErro: %d%s\n", RED, resultado, RESET);
        exit(ERRO_CODIFICACAO);
    }
		
		printf("%s>>>>>%s %s%s%s\n", BOLD_BLACK, RESET, GREEN, string, RESET);

    return 0;
}

/* $RCSfile$ */
