
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao:
 *:q
 * $Author: gabriel.depaula $
 * $Date: 2024/05/27 17:21:12 $
 * $Log: aula0403b.c,v $
 * Revision 1.2  2024/05/27 17:21:12  gabriel.depaula
 * ;
 *
 * Revision 1.1  2024/05/27 06:37:26  gabriel.depaula
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
	usi numeroAuxiliar = 1;
	long double numerador;
	long double denominador;

	if (termo == 0){
		
		return 0;
	
	}

	else{

		do{
			numerador = CalcularExponencial (-1, numeroAuxiliar + 1);
			denominador = CalcularExponencial (numeroAuxiliar, numeroAuxiliar);
			printf ("\nnumerador: %Lf\n", numerador);
			printf ("\ndenominador: %Lf\n", denominador);
			soma += numerador / denominador;
			++numeroAuxiliar;

		} while (numeroAuxiliar <= termo);
	}
	
	return soma;
}



















/* $RCSfile: aula0403b.c,v $ */
