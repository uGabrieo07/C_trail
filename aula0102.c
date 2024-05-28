
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
 * $Date: 2024/04/20 02:26:16 $
 * $Log: aula0102.c,v $
 * Revision 1.3  2024/04/20 02:26:16  gabriel.depaula
 * *** empty log message ***
 *
 * Revision 1.2  2024/04/20 02:06:51  gabriel.depaula
 * foi adcionado o operador <= na verificacao do intervalo do numero de colunas
 *
 * Revision 1.1  2024/04/20 01:59:31  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "cores.h"
#include "aula0101.h"

#define NUMERO_ARGUMENTOS_VALIDO				2
#define SUCESSO							0
#define NUMERO_ARGUMENTOS_INVALIDO				1
#define BASE_INVALIDA						2
#define TAMANHO_MAXIMO_LONG_UNSIGNED_EXCEDIDO			3
#define TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO			4	
#define ARGUMENTO_INVALIDO					5
#define NUMERO_DE_COLUNAS_VALIDO				6
#define NUMERO_DE_COLUNAS_INVALIDO				7
#define END_OF_STRING					      '\0'

int
main (int argc, char *argv []) 
{
	us  numeroDeColunasUs;
	ul  numeroDeColunasUl; 
	char *validacao;
	numeroDeColunasUl = strtoul (argv [1], &validacao, 10);
	
	if (argc != NUMERO_ARGUMENTOS_VALIDO)
	{
		printf ("%s\nUso: %s <numero>\n\n%s", RED, argv [0], RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}


	if (errno == EINVAL)
	{
		printf ("%s\nBase invalida.\n\n%s", RED, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("%s\nValor maximo do tipo long unsigned (%lu) foi excedido.\n\n%s", RED, ULONG_MAX, RESET);
		exit (TAMANHO_MAXIMO_LONG_UNSIGNED_EXCEDIDO);
	}

	if (numeroDeColunasUl > USHRT_MAX)
	{
		printf ("%s\nValor maximo do tipo short unsigned (%u) foi excedido.\n\n%s", RED, UINT_MAX, RESET);
		exit (TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

  	if (*validacao != END_OF_STRING)
  	{
		printf ("%s\nArgumento contem caractere invalido: \'%c\'\n%s", RED, *validacao, RESET);
		exit (ARGUMENTO_INVALIDO);
	}
	
	if ((1 <= numeroDeColunasUl) && (numeroDeColunasUl <= 500)){
		numeroDeColunasUs = (us) numeroDeColunasUl;
		ExibirCabecalho (numeroDeColunasUs);
		exit (SUCESSO);
		
	}

	if (!((1 <= numeroDeColunasUl) && (numeroDeColunasUl <= 500))){
		printf ("%sO numero de colunas deve estar entre 1 e 500.%s", RED, RESET);
		exit (NUMERO_DE_COLUNAS_INVALIDO);
	}

	return SUCESSO;
}

/* $RCSfile: aula0102.c,v $ */
