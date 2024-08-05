
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

#include <stdio.h>
#include <stdlib.h>
#include "cores.h"
#include "aula0901.h"

#define SUCESSO																																	0
#define NUMERO_ARGUMENTOS_INVALIDO																							1
#define ERRO_EXIBIR_CONTEUDO_ARQUIVO                                            2

int
main (int argc, char *argv[])
{

  if (argc != 2){
    printf ("Uso: %s <numero_inteiro>\n", argv[0]);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  char *nomeArquivo = argv[1];

  tipoErros resultado = ExibirConteudoArquivo(nomeArquivo);

  if(resultado != ok){
    printf("%sErro ao ler o arquivo: %d%s\n", RED, resultado, RESET);
    exit(ERRO_EXIBIR_CONTEUDO_ARQUIVO);
  }

  return SUCESSO;
  
}

/* $RCSfile$ */
