
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
 * $Date: 2024/06/07 18:19:13 $
 * $Log: aula0503.c,v $
 * Revision 1.1  2024/06/07 18:19:13  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#define _XOPEN_SOURCE 1000
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include "cores.h"
#include "aula0501.h"

#define NUMERO_ARGUMENTOS																					5 + (2 * NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS)
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define ARGUMENTO_INVALIDO_NA_MATRIZA															3
#define ARGUMENTO_INVALIDO_NA_MATRIZB 														4
#define ARGUMENTO_INVALIDO_NAS_DIMENSOES_DE_A											5
#define ARGUMENTO_INVALIDO_NAS_DIMENSOES_DE_B											6
#define BASE_INVALIDA																							7	
#define TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO													8
#define TAMANHO_MATRIZA_INVALIDO																	9
#define TAMANHO_MATRIZB_INVALIDO																	10
#define MATRIZA_INVALIDA																					11
#define MATRIZB_INVALIDA																					12
#define NUMERO_NEGATIVO																						13
#define END_OF_STRING																							'\0'

int
main (int argc, char *argv []) 
{
	us numeroLinhasA;
	us numeroColunasA;
	us numeroLinhasB;
	us numeroColunasB;
	us linha;
	us coluna;
	us index;
	char *verificacaoMatrizA;
	char *verificacaoMatrizB;
	char *verificacaoLinhasA;
	char *verificacaoColunasA;
	char *verificacaoLinhasB;
	char *verificacaoColunasB;	


	if (argc > NUMERO_ARGUMENTOS)
	{
		printf ("%s\nUso: %s <numero_de_linhas> <numero_de_colunas> a11 ... a1%hu ... a%hu1 ... a%hu%hu%s\n",
			RED,
			argv [0],
			NUMERO_MAXIMO_COLUNAS,
			NUMERO_MAXIMO_LINHAS,
			NUMERO_MAXIMO_LINHAS,
			NUMERO_MAXIMO_COLUNAS,
			RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if ((argv[1][0] == '-') || (argv[2][0] == '1')){
		printf ("\n%sO numero de linhas e colunas da matriz nao podem ser negativos.%s\n\n", RED, RESET);
		exit (NUMERO_NEGATIVO);
	}
	
	numeroLinhasA = (us) strtoul (argv [1], &verificacaoLinhasA, 10);	
	numeroColunasA = (us) strtoul (argv [2], &verificacaoColunasA, 10);
	numeroLinhasB = (us) strtoul (argv [3], &verificacaoLinhasB, 10);
	numeroColunasB = (us) strtoul (argv [4], &verificacaoColunasB, 10);

	if ((*verificacaoLinhasA != END_OF_STRING) || (*verificacaoColunasA != END_OF_STRING)){
		printf ("%s\nO numero de colunas ou o numero de linhas da matriz A contem argumento invalido (diferente de unsigned short).%s\n", RED, RESET);
		exit (ARGUMENTO_INVALIDO_NAS_DIMENSOES_DE_A);
	}

	if ((*verificacaoLinhasB != END_OF_STRING) || (*verificacaoColunasB != END_OF_STRING)){
		printf ("%s\nO numero de colunas ou o numero de linhas da matriz B contem argumento invalido (diferente de unsigned short).%s\n", RED, RESET);
		exit (ARGUMENTO_INVALIDO_NAS_DIMENSOES_DE_B);
	}

	if ((numeroLinhasA > NUMERO_MAXIMO_LINHAS) || (numeroColunasA > NUMERO_MAXIMO_COLUNAS)){
		printf ("%s\nO numero de linhas e colunas da matriz A devem ser, NO MAXIMO, igual a 100.%s\n", RED, RESET);
		exit (TAMANHO_MATRIZA_INVALIDO);
	}
	

	if ((numeroLinhasB > NUMERO_MAXIMO_LINHAS) || (numeroColunasB > NUMERO_MAXIMO_COLUNAS)){
		printf ("%s\nO numero de linhas e colunas da matriz B devem ser, NO MAXIMO, igual a 100.%s\n", RED, RESET);
		exit (TAMANHO_MATRIZB_INVALIDO);
	}
	
	if ((argc - 5 - numeroLinhasB * numeroColunasB > numeroLinhasA * numeroColunasA) || (argc - 5 - numeroLinhasB * numeroColunasB < numeroLinhasA * numeroColunasA)){
		printf ("\n%sA dimensao  da matriz A nao coincide com o numero de argumentos inserido.%s\n\n", RED, RESET);
		exit (MATRIZA_INVALIDA);
	}	


	if ((argc - 5 - numeroLinhasA * numeroColunasA > numeroLinhasB * numeroColunasB) || (argc - 5 - numeroLinhasA * numeroColunasA < numeroLinhasB * numeroColunasB)){
		printf ("\n%sA dimensao da matriz B nao coincide com o numero de argumentos inserido.%s\n\n", RED, RESET);
		exit (MATRIZB_INVALIDA);
	}		  				


	ld matrizA [numeroLinhasA][numeroColunasA];
	ld matrizB [numeroLinhasB][numeroColunasB];
	ld matrizProduto [numeroLinhasA][numeroColunasB];
	index = 5;


	for (linha = 0; linha < numeroLinhasA; ++linha){
		for (coluna = 0; coluna < numeroColunasA; ++coluna){
			matrizA [linha][coluna] = strtold (argv [index], &verificacaoMatrizA); 
			++index;

			if (*verificacaoMatrizA != END_OF_STRING)
			{		
				printf ("%s\nA matriz 'A' contem um argumento invalido: \'%c\'\n%s\n", RED, *verificacaoMatrizA, RESET);
				exit (ARGUMENTO_INVALIDO_NA_MATRIZA);
			}
		}
	}
	for (linha = 0; linha < numeroLinhasB; ++linha){
		for (coluna = 0; coluna < numeroColunasB; ++coluna){
			matrizB [linha][coluna] = strtold (argv [index], &verificacaoMatrizB);
			++index;
					
			if (*verificacaoMatrizB != END_OF_STRING)
			{
				printf ("%s\nA matriz 'B' contem um argumento invalido: \'%c\'\n%s\n", RED, *verificacaoMatrizB, RESET);
				exit (ARGUMENTO_INVALIDO_NA_MATRIZB);
			}	
		}
	}
	
	
	if (errno == EINVAL){
		printf ("%s\nBase invalida.%s", RED, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE){
		printf ("%s\nValor maximo do tipo long double(%Lf) ou unsigned short(%hu) foram excedidos.\n\n%s", RED, LDBL_MAX, USHRT_MAX, RESET);
		exit (TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO);
	}
	
	
	MultiplicarMatrizes (numeroLinhasA, numeroColunasA, numeroLinhasB, numeroColunasB, matrizA, matrizB, matrizProduto);
	ExibirMatriz (numeroLinhasA, numeroColunasB, matrizProduto);
	
	return SUCESSO;
}





/* $RCSfile: aula0503.c,v $ */
