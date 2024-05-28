
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
 * $Date: 2024/05/04 01:59:36 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2024/05/04 01:59:36  gabriel.depaula
 * Initial revision
 *
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
#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "cores.h"
#include "aula0201.h"

#define NUMERO_ARGUMENTOS_VALIDO																	3
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define ARGUMENTO_INVALIDO_EM_X																		2
#define ARGUMENTO_INVALIDO_EM_Y																		3
#define NUMERO_NEGATIVO_INVALIDO																	4
#define BASE_INVALIDA																							5
#define TAMANHO_MAXIMO_LONG_LONG_UNSIGNED_EXCEDIDO								6	
#define ZERO_DIVISION																							7
#define END_OF_STRING																						'\0'

int
main (int argc, char *argv []) 
{
	ull numeroX;
	ull numeroY;
	ull maximoDivisorComumXY;
	char *validacaoNumeroX;
	char *validacaoNumeroY;
	
	if (argc != NUMERO_ARGUMENTOS_VALIDO)
	{
		printf ("%s\nUso: %s <numeroX> <numeroY>\n\n%s", RED, argv [0], RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	numeroX = strtoull (argv [1], &validacaoNumeroX, 10);
	numeroY = strtoull (argv [2], &validacaoNumeroY, 10);
	

  if (*validacaoNumeroX != END_OF_STRING)
  {
		printf ("%s\nArgumento referente ao numero X contem caractere invalido: \'%c\'\n%s", RED, *validacaoNumeroX, RESET);
		exit (ARGUMENTO_INVALIDO_EM_X);
	}

  if (*validacaoNumeroY != END_OF_STRING)
  {
		printf ("%s\nArgumento referente ao numero Y contem caractere invalido: \'%c\'\n%s", RED, *validacaoNumeroY, RESET);
		exit (ARGUMENTO_INVALIDO_EM_Y);
	}

	if ((argv[1][0] == '-') || (argv[2][0] == '-'))
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
		printf ("%s\nValor maximo do tipo long long unsigned (%llu) foi excedido.\n\n%s", RED, ULLONG_MAX, RESET);
		exit (TAMANHO_MAXIMO_LONG_LONG_UNSIGNED_EXCEDIDO);
	}

	
	maximoDivisorComumXY = CalculaMaximoDivisorComum (numeroX,numeroY);

	if (maximoDivisorComumXY == 0)
	{
		printf ("%s\nOs numeros X e Y nao podem ser ambos iguais a zero.\n\n%s", RED, RESET);
		exit (ZERO_DIVISION);
	}
	
	else
		printf ("%s\nmdc(%llu,%llu) = %llu.\n\n%s", GREEN, numeroX, numeroY, maximoDivisorComumXY, RESET); 
	
	return SUCESSO;
}

/* $RCSfile: aula0202.c,v $ */
