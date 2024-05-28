
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
 * $Date: 2024/05/13 05:09:36 $
 * $Log: aula0301d.c,v $
 * Revision 1.1  2024/05/13 05:09:36  gabriel.depaula
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
	ull somaDosAnteriores, numeroAuxiliar1 = 0, numeroAuxiliar2 = 1, limite = 1;	

	if (termo <= 1){
		return termo;
	}

	else{
		while(limite < termo){
			somaDosAnteriores = numeroAuxiliar1 + numeroAuxiliar2;
			numeroAuxiliar1 = numeroAuxiliar2;
			numeroAuxiliar2 = somaDosAnteriores;
			++limite;
		}

	return numeroAuxiliar2;
	}
}


/* $RCSfile: aula0301d.c,v $ */
