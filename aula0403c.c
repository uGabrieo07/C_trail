
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
 * $Date: 2024/05/27 17:21:12 $
 * $Log: aula0403c.c,v $
 * Revision 1.1  2024/05/27 17:21:12  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/




#include <stdio.h>
#include "aula0401.h"
#include "cores.h"

float
CalcularSerieHarmonicaAlternada (usi termo)
{
	float soma;
	usi numeroAuxiliar;
	long double numerador;
	long double denominador;

	if (termo == 0){
		
		return 0;
	
	}

	else{
		for (numeroAuxiliar = 1; numeroAuxiliar <= termo; ++numeroAuxiliar){
			
			numerador = CalcularExponencial (-1, numeroAuxiliar + 1);
			denominador = CalcularExponencial (numeroAuxiliar, numeroAuxiliar);
			soma += numerador / denominador;
		
		}
	}
	
	return soma;
}




/* $RCSfile: aula0403c.c,v $ */
