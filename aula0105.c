
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
 * $Date: 2024/07/04 16:35:52 $
 * $Log: aula0105.c,v $
 * Revision 1.2  2024/07/04 16:35:52  gabriel.depaula
 * *** empty log message ***
 *
 * Revision 1.1  2024/04/21 23:19:31  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include "aula0101.h"
#include "cores.h"
#include <string.h>

#define CARACTERES_MAXIMO	50
#define COLUNAS_TERMINAL	100
#define FIM_STRING 		'\0'



int
main (int argc, char *argv[]){
	printf ("\n");
	ExibirCabecalho (100);
	printf ("\n");

	int numeroAuxiliar,tamanhoDoNome, espacosInicio, espacosFim;
	
	if (argc == 2){
		tamanhoDoNome = strlen (argv[1]);
		espacosInicio = (COLUNAS_TERMINAL - tamanhoDoNome) / 2;
		espacosFim = COLUNAS_TERMINAL - espacosInicio -tamanhoDoNome;

		for (numeroAuxiliar = 0; numeroAuxiliar < espacosInicio; ++numeroAuxiliar){
			printf (" ");
		}

		printf("\e[38;5;9;4m\"%s\"\e[0m\n",argv[1]);

		for (numeroAuxiliar = 0 ; numeroAuxiliar <  espacosFim; ++numeroAuxiliar){
			printf (" ");
		}

		ExibirHifens (100);
	}

	if (argc > 2){
		int numeroDeArgumentos = argc - 1;

		tamanhoDoNome = numeroDeArgumentos + (numeroDeArgumentos - 1);

		espacosInicio = (COLUNAS_TERMINAL - tamanhoDoNome) / 2;
		espacosFim = COLUNAS_TERMINAL - espacosInicio - tamanhoDoNome;

		
		for (numeroAuxiliar = 0; numeroAuxiliar < espacosInicio; ++numeroAuxiliar){

			printf (" ");
		
		}


		if (tamanhoDoNome <= CARACTERES_MAXIMO){
			int indexUltimoArgumento = numeroDeArgumentos;
			for (numeroAuxiliar = 1; numeroAuxiliar <= numeroDeArgumentos; ++numeroAuxiliar){
				if (numeroAuxiliar == 1){
				
					printf ("\e[4;38;5;196m\"%s \e[0m", argv[numeroAuxiliar]); 
				
				}
				if ((numeroAuxiliar != indexUltimoArgumento) && (numeroAuxiliar != 1)){

					printf ("\e[4;38;5;196m%s \e[0m", argv[numeroAuxiliar]);
				
				}

				if (numeroAuxiliar == indexUltimoArgumento){
					printf ("\e[4;38;5;196m%s\"\e[0m", argv[numeroAuxiliar]);
					printf ("\n");
					ExibirHifens (100);
				}
			}	
		}


		for  (numeroAuxiliar = 0; numeroAuxiliar < espacosFim; ++numeroAuxiliar){

			printf (" ");

		}

		

		if (tamanhoDoNome > CARACTERES_MAXIMO){

			printf ("%sTAMANHO DE NOME MAXIMO EXCEDIDO%s",RED,RESET);
		
		}
			
		

			
	
	}
return 0;
}


/* $RCSfile: aula0105.c,v $ */
