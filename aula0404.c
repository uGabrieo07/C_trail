
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
 * $Date: 2024/05/27 06:37:08 $
 * $Log: aula0404.c,v $
 * Revision 1.1  2024/05/27 06:37:08  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include "cores.h"
#include "aula0401.h"

#define NUMERO_ARGUMENTOS_VALIDO																	2
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define ARGUMENTO_INVALIDO_NO_PERCENTUAL													2
#define NUMERO_NEGATIVO_INVALIDO																	3
#define BASE_INVALIDA																							4
#define TAMANHO_MAXIMO_FLOAT_EXCEDIDO															5
#define PERCENTUAL_INVALIDO																				6
#define END_OF_STRING																						'\0'
#define PONTO_FLUTUANTE																					'.'

int
main (int argc, char *argv []) 
{
	float percentual;
	usi termo;
	char *validacaoDoPercentual;
	float valorTermoAtual;
	float valorTermoAnterior;
	
	if (argc != NUMERO_ARGUMENTOS_VALIDO)
	{
		printf ("%s\nUso: %s <percentual>\n\n%s", RED, argv [0], RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	percentual = strtof (argv [1], &validacaoDoPercentual);	
		
	if (*validacaoDoPercentual != END_OF_STRING && *validacaoDoPercentual != PONTO_FLUTUANTE)
  {
		printf ("%s\nArgumento referente ao percentual contem caractere invalido: \'%c\'\n%s", RED, *validacaoDoPercentual, RESET);
		exit (ARGUMENTO_INVALIDO_NO_PERCENTUAL);
	}
	
	if (percentual <= 0 || percentual >= 1){
		printf ("%s\nO valor de P deve estar ENTRE 0 e 1.%s\n", RED, RESET);
		exit (PERCENTUAL_INVALIDO);
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
		printf ("%s\nValor maximo do tipo float (%f) foi excedido.\n\n%s", RED, FLT_MAX, RESET);
		exit (TAMANHO_MAXIMO_FLOAT_EXCEDIDO);
	}


	else{	
			while (fabsf (valorTermoAtual - valorTermoAnterior) >= percentual * valorTermoAnterior){
				
				valorTermoAnterior = valorTermoAtual;
				valorTermoAtual = CalcularSerieHarmonicaAlternada (termo);
				
				if (termo % 2 == 0 || termo % 2 == 2){
				
					printf ("%s%sS (%hu): %.10lf%s%s%s\n", BLACK, WHITE_BACKGROUND, termo, valorTermoAtual, BLACK, WHITE_BACKGROUND, RESET);
			
				}	
			
				if (termo % 2 != 0){
				
					printf ("%s%sS (%hu): %.10lf%s%s%s\n", WHITE, BLACK_BACKGROUND, termo, valorTermoAtual, WHITE, BLACK_BACKGROUND, RESET);

				}
				
				++termo;

			}
		}
	return SUCESSO;
}


/* $RCSfile: aula0404.c,v $ */
