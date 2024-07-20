
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
 * $Date: 2024/07/04 16:16:08 $
 * $Log: aula0403a.c,v $
 * Revision 1.3  2024/07/04 16:16:08  gabriel.depaula
 * *** empty log message ***
 *
 * Revision 1.2  2024/05/27 17:21:12  gabriel.depaula
 * ;
 *
 * Revision 1.1  2024/05/27 06:37:08  gabriel.depaula
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
	float valorDoUltimoTermo;

	if (termo == 0){
		
		return 0;
	
	}
	
	else{

		valorDoUltimoTermo = 1 / CalcularExponencial(termo,termo);

		if (termo % 2 == 0){
			return CalcularSerieHarmonicaAlternada (termo - 1) - valorDoUltimoTermo;
		}
		
		else{

			return CalcularSerieHarmonicaAlternada (termo - 1) + valorDoUltimoTermo;
		}
	}
}



















/* $RCSfile: aula0403a.c,v $ */
