
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
 * $Date: 2024/06/07 18:19:13 $
 * $Log: aula0501.h,v $
 * Revision 1.1  2024/06/07 18:19:13  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/






#ifndef _AULA0501_
#define _AULA0501_ "@(#)aula0501.h $Revision: 1.1 $"
 
typedef long double ld;
typedef unsigned short us;
typedef enum 
{
	ok,
	matrizInvalida	
}
tiposErros;

#define NUMERO_MAXIMO_COLUNAS															100
#define NUMERO_MAXIMO_LINHAS															100

tiposErros
ExibirMatriz (us,      /*numero de linhas da matriz*/ 
							us,      /* numero de colunas da matriz*/	
							ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS ] /*matriz*/);

tiposErros
MultiplicarMatrizes (us, us, us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
										 ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);

tiposErros
ObterMatrizTransposta (us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld [NUMERO_MAXIMO_COLUNAS][NUMERO_MAXIMO_LINHAS]);

tiposErros
CalcularDeterminanteMatriz (us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld *);

tiposErros
CalcularMenorComplementar (us, us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld *);

tiposErros
CalcularComplementoAlgebrico (us, us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld *);
#endif 












/* $RCSfile: aula0501.h,v $ */
