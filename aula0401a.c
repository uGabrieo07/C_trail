
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
 * $Date: 2024/05/27 18:09:55 $
 * $Log: aula0401a.c,v $
 * Revision 1.2  2024/05/27 18:09:55  gabriel.depaula
 * *** empty log message ***
 *
 * Revision 1.1  2024/05/26 02:43:44  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <limits.h>
#include <math.h>
#include "aula0401.h"

ld
CalcularExponencial (double base, int expoente)
{	

	if (base == 0 && expoente == 0){
		return 1;
	}

	if (base == 0 && expoente < 0){
		return HUGE_VAL;
	}

	if (base != 0 && expoente == 0 ){
		return 1;
	}

	if (base != 0 && expoente < 0){
		return 1 / (base * CalcularExponencial (base, -1 * expoente - 1));	
	}
	
	return base * CalcularExponencial (base, expoente - 1);
}

















/* $RCSfile: aula0401a.c,v $ */
