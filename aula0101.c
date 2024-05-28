
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
 * $Date: 2024/04/20 05:31:46 $
 * $Log: aula0101.c,v $
 * Revision 1.2  2024/04/20 05:31:46  gabriel.depaula
 * foi adcionada a declaracao da funcao ExibirHifens.
 *
 * Revision 1.1  2024/04/20 01:58:28  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "aula0101.h"
#include "cores.h"

/*Definindo a funcao.*/
void
ExibirCabecalho (us numeroDeColunas)
{       
	int linha;/* variavel que define em qual linha estamos (centenas = 0, dezenas = 1 ou unidades = 2).*/
	int numeroAuxiliar;/*variavel auxilar para obtermos os digitos a serem impressos.*/

	for (linha = 0; linha < 3; ++linha){/*loop que incrementar a variavel (linha) e define em qual linha estamos.*/
		for(numeroAuxiliar = 0; numeroAuxiliar <= numeroDeColunas; ++numeroAuxiliar){

			if (linha == 0){/*se estivermos na lnha das centenas...*/
				printf ("%s%s%d%s%s%s", BLACK, WHITE_BACKGROUND,numeroAuxiliar/100, BLACK, WHITE_BACKGROUND,RESET);
			}

			if (linha == 1){/*se estivermos na linha das dezenas...*/
				printf ("%s%s%d%s%s%s", BLACK, WHITE_BACKGROUND, (numeroAuxiliar/10)%10, BLACK, WHITE_BACKGROUND,RESET);
			}
			
			if (linha == 2){/*se estivermos na linha das unidades...*/
				printf("%s%s%d%s%s%s", BLACK, WHITE_BACKGROUND, numeroAuxiliar%10, BLACK, WHITE_BACKGROUND,RESET);
			}
		}

	printf ("\n");/*print que faz a passagem  para a proxima linha*/
	
	}
}

void
ExibirHifens (us numeroDeHifens)
{	
	int numeroAuxiliar;
	for (numeroAuxiliar = 0; numeroAuxiliar <= numeroDeHifens; ++numeroAuxiliar){
		printf ("%s%s-%s%s%s",BLACK_BACKGROUND,BLACK,BLACK_BACKGROUND,BLACK,RESET);
	}
	printf ("\n");
	for (numeroAuxiliar = 0; numeroAuxiliar <= numeroDeHifens; ++numeroAuxiliar){
		printf ("%s%s-%s%s%s",WHITE,BLACK_BACKGROUND,WHITE,BLACK_BACKGROUND,RESET);
	}
	printf ("\n");
	for (numeroAuxiliar = 0; numeroAuxiliar <= numeroDeHifens; ++numeroAuxiliar){
		printf ("%s%s-%s%s%s",BLACK_BACKGROUND,BLACK,BLACK_BACKGROUND,BLACK,RESET);	
	}
	printf ("\n");	
}






/* $RCSfile: aula0101.c,v $ */
