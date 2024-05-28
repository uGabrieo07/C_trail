
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
 * $Date: 2024/05/13 03:46:05 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2024/05/13 03:46:05  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include "aula0301.h"
#include "cores.h"


ull CalcularTermoSerieFibonacci (us termo)
{
	ull valorDoTermo;

	if (termo <=1){
		valorDoTermo = termo;
	}

	else{
		valorDoTermo = CalcularTermoSerieFibonacci (termo - 1) + CalcularTermoSerieFibonacci (termo - 2);	
	}

	return valorDoTermo;
}





















/* $RCSfile: aula0301a.c,v $ */
