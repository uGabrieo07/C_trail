
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
 * $Date: 2024/05/13 04:52:46 $
 * $Log: aula0301c.c,v $
 * Revision 1.1  2024/05/13 04:52:46  gabriel.depaula
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
	ull somaDosAnteriores, numeroAuxiliar1 = 0, numeroAuxiliar2 = 1, limite;	

	if (termo <= 1){
		return termo;
	}

	else{
		for (limite = 1; limite < termo; ++limite){
			somaDosAnteriores = numeroAuxiliar1 + numeroAuxiliar2;
			numeroAuxiliar1 = numeroAuxiliar2;
			numeroAuxiliar2 = somaDosAnteriores;
		}

	return numeroAuxiliar2;
	}
}














/* $RCSfile: aula0301c.c,v $ */
