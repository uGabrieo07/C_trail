
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
 * $Date: 2024/04/22 04:28:23 $
 * $Log: aula0106.c,v $
 * Revision 1.1  2024/04/22 04:28:23  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#include "cores.h"
#include "aula0101.h"
#include <stdio.h>


int
main (int argc, char *argv[])
{


	printf ("\n");
	ExibirHifens (100);
	printf ("\n");
	
	printf ("%sTamanhos dos Tipos Basicos%s\n\n",UNDERLINE_WHITE,RESET);

	int coluna;
	int linha;

	for (linha = 0; linha <= 4; ++linha){
		for (coluna = 1; coluna < 100; ++coluna){
			if (linha == 0){
				if (coluna == 1){
					printf ("%svoid:%s",GREEN,RESET);
				}
				if ((4 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(void),RESET,YELLOW,sizeof(void)>1?"bytes":"byte",RESET);
				}
			
			}
				
			if (linha == 1){
				if (coluna == 1){
					printf ("%schar:%s",GREEN,RESET);
				}
				if ((4 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(char),RESET,YELLOW,sizeof(char)>1?"bytes":"byte",RESET);
				}
			
			}
			
	
			if (linha == 2){
				if (coluna == 1){
					printf ("%sint:%s",GREEN,RESET);
				}
				if ((3 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(int),RESET,YELLOW,sizeof(int)>1?"bytes":"byte",RESET);
				}
			
			}
	
			if (linha == 3){
				if (coluna == 1){
					printf ("%sfloat:%s",GREEN,RESET);
				}
				if ((5 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(float),RESET,YELLOW,sizeof(float)>1?"bytes":"byte",RESET);
				}
			
			}
	
			if (linha == 4){
				if (coluna == 1){
					printf ("%sdouble:%s",GREEN,RESET);
				}
				if ((6 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(double),RESET,YELLOW,sizeof(double)>1?"bytes":"byte",RESET);
				}
			
			}
		}
	}

	
	printf ("\n");
	ExibirHifens (100);
	printf ("\n");

	printf ("%sTamanhos dos Modificadores de Sinal%s\n\n",UNDERLINE_WHITE,RESET);
	for (linha = 0; linha <= 4; ++linha){
		for (coluna = 1; coluna < 100; ++coluna){
			if (linha == 0){
				if (coluna == 1){
					printf ("%ssigned:%s",GREEN,RESET);
				}
				if ((6 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(signed),RESET,YELLOW,sizeof(signed)>1?"bytes":"byte",RESET);
				}
			
			}
				
			if (linha == 1){
				if (coluna == 1){
					printf ("%sunsigned:%s",GREEN,RESET);
				}
				if ((8 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(unsigned),RESET,YELLOW,sizeof(unsigned)>1?"bytes":"byte",RESET);
				}
			}
			
		}
	}
			
	printf ("\n");
	ExibirHifens (100);
	printf ("\n");

	printf ("%sTamanhos dos Modificadores de Largura%s\n\n",UNDERLINE_WHITE,RESET);
	for (linha = 0; linha <= 4; ++linha){
		for (coluna = 1; coluna < 100; ++coluna){
			if (linha == 0){
				if (coluna == 1){
					printf ("%sshort:%s",GREEN,RESET);
				}
				if ((5 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(short),RESET,YELLOW,sizeof(short)>1?"bytes":"byte",RESET);
				}
			
			}
				
			if (linha == 1){
				if (coluna == 1){
					printf ("%slong:%s",GREEN,RESET);
				}
				if ((4 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(long),RESET,YELLOW,sizeof(long)>1?"bytes":"byte",RESET);
				}
			
			}
			
	
			if (linha == 2){
				if (coluna == 1){
					printf ("%slong long:%s",GREEN,RESET);
				}
				if ((9 < coluna) && (coluna < 91)){
					printf (" ");
				}
				if (coluna == 91){
					printf ("%s%lu%s %s%s%s\n", YELLOW,sizeof(long long),RESET,YELLOW,sizeof(long long)>1?"bytes":"byte",RESET);
				}
			
			}
	
			
		}

	}
	
	printf ("\n");
	ExibirHifens (100);
	printf ("\n");

return 0;
}
/* $RCSfile: aula0106.c,v $ */
