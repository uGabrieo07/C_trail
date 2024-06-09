
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
 * $Log: aula0502.c,v $
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

#define NUMERO_ARGUMENTOS																					3 + (NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS)
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define ARGUMENTO_INVALIDO_NA_MATRIZ															3
#define ARGUMENTO_INVALIDO_NAS_DIMENSOES													4
#define BASE_INVALIDA																							5	
#define TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO													6
#define DIMENSAO_INVALIDA																					7
#define MATRIZ_INVALIDA																						8
#define NUMERO_NEGATIVO																						9
#define END_OF_STRING																							'\0'

int
main (int argc, char *argv []) 
{
	us numeroLinhas;
	us numeroColunas;
	us linha;
	us coluna;
	char *verificacaoMatriz;
	char *verificacaoLinhas;
	char *verificacaoColunas;	


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
	
	numeroLinhas = (us) strtoul (argv [1], &verificacaoLinhas, 10);	
	numeroColunas = (us) strtoul (argv [2], &verificacaoColunas, 10);


	if ((*verificacaoLinhas != END_OF_STRING) || (*verificacaoColunas != END_OF_STRING)){
		printf ("%s\nO numero de colunas ou o numero de linhas contem argumento invalido (diferente de unsigned short).%s\n", RED, RESET);
		exit (ARGUMENTO_INVALIDO_NAS_DIMENSOES);
	}
	
	if ((numeroLinhas > NUMERO_MAXIMO_LINHAS) || (numeroColunas > NUMERO_MAXIMO_COLUNAS)){
		printf ("%s\nO numero de linhas e o numero de colunas devem ser, NO MAXIMO, igual a 100.%s\n", RED, RESET);
		exit (DIMENSAO_INVALIDA);
	}
		
	if ((argc - 3 > numeroLinhas * numeroColunas) || (argc - 3 < numeroLinhas * numeroColunas)){
		printf ("\n%sA dimensao (%hu X %hu) da matriz nao coincide com o numero de argumentos inserido(%d)%s\n\n", RED, numeroLinhas, numeroColunas, argc - 3, RESET);
		exit (MATRIZ_INVALIDA);
	}		  				

	ld matriz [numeroLinhas][numeroColunas];
	
	for (linha = 0; linha < numeroLinhas; ++linha){
		for (coluna = 0; coluna < numeroColunas; ++coluna){
			matriz [linha][coluna] = strtold (argv [3 + coluna + linha * numeroColunas], &verificacaoMatriz); 
		}
	}

  if (*verificacaoMatriz != END_OF_STRING)
  {
		printf ("%s\nA matriz contem um argumento invalido: \'%c\'\n%s\n", RED, *verificacaoMatriz, RESET);
		exit (ARGUMENTO_INVALIDO_NA_MATRIZ);
	}
	
	if (errno == EINVAL){
		printf ("%s\nBase invalida.%s", RED, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("%s\nValor maximo do tipo long double(%Lf) ou unsigned short(%hu) foram excedidos.\n\n%s", RED, LDBL_MAX, USHRT_MAX, RESET);
		exit (TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO);
	}

	ExibirMatriz (numeroLinhas, numeroColunas, matriz);

	return SUCESSO;
}





/* $RCSfile: aula0502.c,v $ */
