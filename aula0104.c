
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
 * $Date: 2024/04/20 21:55:36 $
 * $Log: aula0104.c,v $
 * Revision 1.1  2024/04/20 21:55:36  gabriel.depaula
 * Initial revision
 *
 * Revision 1.1  2024/04/20 07:40:10  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include "aula0101.h"

int
main() { /*Funcao que imprime as 256 cores atreladas aos seus respectivos numeros*/
	printf ("\n");
	ExibirCabecalho (80);
	printf ("\n");
	int numeroAuxiliar;/*Numero auxiliar para definirmos as cores e quando acontecera a quebra de linha*/
	for (numeroAuxiliar = 0; numeroAuxiliar < 256; ++numeroAuxiliar) {/*laco de repeticao para iterar sobre as cores*/
		if ((0 <= numeroAuxiliar) && (numeroAuxiliar < 10)){
			printf ("\e[38;5;%dm 00%d \e[38;5;%dm",numeroAuxiliar,numeroAuxiliar,numeroAuxiliar);
		}
		if ((10 <= numeroAuxiliar) && (numeroAuxiliar < 100)){
			printf ("\e[38;5;%dm 0%d \e[38;5;%dm",numeroAuxiliar,numeroAuxiliar,numeroAuxiliar);
		}
		if (numeroAuxiliar >= 100){
			printf ("\e[38;5;%dm %d \e[38;5;%dm", numeroAuxiliar,numeroAuxiliar,numeroAuxiliar);
		}
		if ((numeroAuxiliar + 1) % 16 == 0){
			printf ("\n");/*Faz a quebra de linha a cada cores*/
		}
	}
	return 0;
}
 
/* $RCSfile: aula0104.c,v $ */
