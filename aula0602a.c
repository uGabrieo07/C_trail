
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


#define _XOPEN_SOURCE 1000
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include "cores.h"
#include "aula0601.h"

#define NUMERO_ARGUMENTOS																					9
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define BASE_INVALIDA																							2	
#define TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO													3
#define DIMENSAO_INVALIDA																					4
#define DIGITO_NEGATIVO_INVALIDO																	5
#define DIGITO_RG_INVALIDO																				6
#define TAMANHO_EXTRAPOLADO																				7
#define END_OF_STRING																							'\0'

int
main (int argc, char *argv []) 
{
	byte indice;
	byte digito;
	char *verificacaoDigitos;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("%s\nUso: %s <oito_primeiros_digitos_rg>%s \n",
			RED,
			argv [0],
			RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indice = 1; indice < argc; indice++){
		if (argv[indice][0] == '-'){
			printf ("%s\nO o numero do Registro Geral, nao pode conter digitos negativos.%s\n", RED, RESET);
			exit (DIGITO_NEGATIVO_INVALIDO);
		}
	}
	
	byte digitosRg[8];
	
	for (indice = 0; indice < NUMERO_ARGUMENTOS - 1; indice++){
		digito = (byte) strtoul (argv[indice + 1], &verificacaoDigitos, 10);

		if (*verificacaoDigitos != END_OF_STRING){
			printf ("%s\nDigito invalido: (%c)%s\n", RED, *verificacaoDigitos, RESET);
			exit (DIGITO_RG_INVALIDO);
		}
		
		if (digito < 0 || digito > 255){
			printf ("%s\nDigito ultrapassa  valor de 1 byte: (%hu)%s\n", RED, digito, RESET);
			exit (TAMANHO_EXTRAPOLADO);
		}
		
		digitosRg[indice] = digito;
	
	}
	if (errno == EINVAL){
		printf ("%s\nBase invalida.%s", RED, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("%s\nValor maximo do tipo unsigned char ou unsigned short foram excedidos.\n%s", RED, RESET);
		exit (TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO);
	}

	for (indice = 0; indice < NUMERO_ARGUMENTOS; indice++){

		if (indice == 0){
			printf ("\nRG: %u", digitosRg[indice]);
		}

		else if (indice == 2 || indice == 5){
			printf (".%u", digitosRg[indice]);
		}
		
		else if (indice == 8) {
			printf ("-%u\n\n", GerarDigitosVerificadoresRg (digitosRg) );
		}
		
		else {
			printf ("%u", digitosRg[indice]);
		}
	} 
	return SUCESSO;
	
}



/* $RCSfile$ */
