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
 * $Date: 2024/05/04 01:59:30 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2024/05/04 01:59:30  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include "aula0201.h"
#include "cores.h"
#include <stdio.h>

#define ZERO_DIVISION																														1


ull
CalculaMaximoDivisorComum (ull numeroX, ull numeroY)
{
ull restoDaDivisao;



if ((numeroY == 0) && (numeroX != 0))
	return numeroX;

if ((numeroX == 0) && (numeroY != 0))
	return numeroY;

if ((numeroX == 0) && (numeroY == 0))
	return 0;

restoDaDivisao = numeroX % numeroY;

if (restoDaDivisao == 0)
	return numeroY;

else
	return CalculaMaximoDivisorComum (numeroY, restoDaDivisao);

}














/* $RCSfile: aula0201a.c,v $ */
