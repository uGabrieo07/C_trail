

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include "cores.h"
#include "aula0401.h"

#define NUMERO_ARGUMENTOS_VALIDO																	3
#define SUCESSO																										0
#define NUMERO_ARGUMENTOS_INVALIDO																1
#define ARGUMENTO_INVALIDO_NA_BASE																2
#define ARGUMENTO_INVALIDO_NO_EXPOENTE														3
#define BASE_INVALIDA																							4
#define TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO													5	
#define END_OF_STRING																						'\0'

int
main (int argc, char *argv []) 
{
	double base;
	int expoente;
	char *validacaoBase;
	char *validacaoExpoente;
	
	if (argc != NUMERO_ARGUMENTOS_VALIDO)
	{
		printf ("%s\nUso: %s <base> <expoente>\n\n%s", RED, argv [0], RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	} 

	base = strtod (argv [1], &validacaoBase);
	expoente = strtol (argv [2], &validacaoExpoente, 10);
	

  if (*validacaoBase != END_OF_STRING)
  {
		printf ("%s\nArgumento referente a base contem caractere invalido: \'%c\'\n%s", RED, *validacaoBase, RESET);
		exit (ARGUMENTO_INVALIDO_NA_BASE);
	}

  if (*validacaoExpoente != END_OF_STRING)
  {
		printf ("%s\nArgumento referente ao expoente contem caractere invalido: \'%c\'\n%s", RED, *validacaoExpoente, RESET);
		exit (ARGUMENTO_INVALIDO_NO_EXPOENTE);
	}
	
	if (errno == EINVAL)
	{
		printf ("%s\nBase inivalida.\n\n%s", RED, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("%s\nValor maximo do tipo double(%f) ou inteiro(%d) foram excedidos.\n\n%s", RED, DBL_MAX, INT_MAX, RESET);
		exit (TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO);
	}
	/*
	printf ("base: %lf", base);
	printf ("expoente: %d", expoente);*/

	else{
		printf ("%s%s%lf^%d:%s%s%s%s%s%Lf%s%s%s\n", YELLOW, BLUE_BACKGROUND, base, expoente, YELLOW, BLUE_BACKGROUND, RESET, RED, WHITE_BACKGROUND, CalcularExponencial (base, expoente),RED, WHITE_BACKGROUND, RESET);
	}
	return SUCESSO;
}
