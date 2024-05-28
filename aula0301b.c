
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
 * $Date: 2024/05/13 04:19:07 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2024/05/13 04:19:07  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/





#include <stdio.h>
#include "aula0301.h"
#include "cores.h"


ull 
CalcularTermoSerieFibonacci (us termo)
{
	ull limite = termo, resultado, numeroAuxiliar1 = 0, numeroAuxiliar2 = 1;	

	if (termo <= 1){
		return termo;
	}

	do {

		resultado = numeroAuxiliar1 + numeroAuxiliar2;
		numeroAuxiliar1 = numeroAuxiliar2;
		numeroAuxiliar2 = resultado;
		--limite;

	} while (limite > 1);

	return resultado;
}

















/* $RCSfile: aula0301b.c,v $ */
