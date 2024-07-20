
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
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifndef _AULA0601_
#define _AULA0601_ "@(#)aula0601.h $Revision$"

#define TAMANHO_MAXIMO_RG										9

typedef unsigned char byte;
typedef enum {ok, rgInvalido} tiposErros;
typedef unsigned short us;

tiposErros
GerarDigitosVerificadoresRg (byte [TAMANHO_MAXIMO_RG ]) /*entrada / saida*/;

tiposErros
ValidarRg ( byte [TAMANHO_MAXIMO_RG]);
#endif

/*	
	for ...
		digitosRg[indice] = strtoul(...)

	8 primeiros digitos inseridos {1, 2, 3, 4, 5, 6, 7, 8, 0}

	codigoRetorno = GerarDigitosVerificadoresRg(digitosRg);
	if(codigoRetorno != ok)
		...

	
	rg final completo { 1, 2, 3, 4, 5, 6, 7, 8, DV}
*/





































/* $RCSfile$ */
