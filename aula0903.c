
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

#define SUCESSO                                                    0
#define ERRO_CONVERSAO                                             1

int 
main(int argc, char *argv[]) {
    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_origem> [arquivo_destino]\n", argv[0]);
        return 1;
    }


    char *arquivoOrigem = argv[1];
    char *arquivoDestino = (argc == 3) ? argv[2] : NULL;

    tipoErros resultado = ConverterArquivoFormatoUnixParaFormatoDos(arquivoOrigem, arquivoDestino);
    if (resultado != ok){
      printf("%sErro ao converter o arquivo de Unix para Dos%s\n", RED, RESET);
      exit(ERRO_CONVERSAO);
    }
    
    printf("%sSucesso na conversao do arquivo Unix para Dos%s\n", GREEN, RESET);
      
    return SUCESSO;
}

/* $RCSfile$ */
