
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
 * $Author: gabriel.depaula $
 * $Date: 2024/05/13 03:46:13 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2024/05/13 03:46:13  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "cores.h"
#include "aula0301.h"

#define NUMERO_ARGUMENTOS_VALIDO																	2
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define ARGUMENTO_INVALIDO_EM_NO_LIMITE														2
#define NUMERO_NEGATIVO_INVALIDO																	3
#define BASE_INVALIDA																							4
#define TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO										5
#define TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO								6	
#define END_OF_STRING																						'\0'

int
main (int argc, char *argv []) 
{
	us limite;
	us numeroAuxiliar;
	char *validacaoDoLimite;
	ull termoSerieFibonacci;
	ull termoAnterior;
	
	if (argc != NUMERO_ARGUMENTOS_VALIDO)
	{
		printf ("%s\nUso: %s <termo>\n\n%s", RED, argv [0], RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	limite = (us) strtoul (argv [1], &validacaoDoLimite, 10);	

  if (*validacaoDoLimite != END_OF_STRING)
  {
		printf ("%s\nArgumento referente ao numero contem caractere invalido: \'%c\'\n%s", RED, *validacaoDoLimite,RESET);
		exit (ARGUMENTO_INVALIDO_EM_NO_LIMITE);
	}

	if (argv[1][0] == '-')
	{
		printf ("%s\nError:insira SOMENTE numeros positivos.\n\n%s", RED, RESET);
		exit (NUMERO_NEGATIVO_INVALIDO);
	}
	
	if (errno == EINVAL)
	{
		printf ("%s\nBase inivalida.\n\n%s", RED, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("%s\nValor maximo do tipo unsigned short (%hu) foi excedido.\n\n%s", RED, USHRT_MAX, RESET);
		exit (TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

	else{
		for (numeroAuxiliar = 0; numeroAuxiliar <= limite; ++numeroAuxiliar){
				termoSerieFibonacci = CalcularTermoSerieFibonacci (numeroAuxiliar);
				
				if (numeroAuxiliar == 0){
					termoSerieFibonacci = 0;
				}
				
				else{
					termoAnterior = CalcularTermoSerieFibonacci (numeroAuxiliar - 1);
				}				

				if (termoSerieFibonacci < termoAnterior){
					printf ("%s%s o termo F (%hu) ultrapassa o valor maximo da variavel unsigned long long.%s", WHITE_BACKGROUND, RED, numeroAuxiliar, RESET);
					exit (TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
				}

				printf ("\n%s%sF (%hu) = %llu%s%s%s\n", BLACK, WHITE_BACKGROUND, numeroAuxiliar, termoSerieFibonacci, BLACK, WHITE_BACKGROUND, RESET);
		}

	}
	return SUCESSO;
}


/* $RCSfile: aula0302.c,v $ */
