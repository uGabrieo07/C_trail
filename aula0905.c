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
#include <unistd.h>
#include <getopt.h>
#include "aula0901.h"
#include "cores.h"

#define SUCESSO                                 0
#define FALHA                                   1

int 
main(int argc, char *argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "hHd:D:s:S:u:U:")) != -1) {
    switch (opt) {
      case 'd':
      case 'D':
        if (ConverterArquivoFormatoUnixParaFormatoDos(optarg, NULL) == ok) {
          printf("%sArquivo convertido de Unix para DOS com sucesso.\n%s", GREEN, RESET);
        } else {
          printf("%sErro ao converter o arquivo de Unix para DOS.\n%s", RED, RESET);
        }
        break;
      case 'u':
      case 'U':
        if (ConverterArquivoFormatoDosParaFormatoUnix(optarg, NULL) == ok) {
          printf("%sArquivo convertido de DOS para Unix com sucesso.\n%s", GREEN, RESET);
        } else {
          printf("%sErro ao converter o arquivo de DOS para Unix.\n%s", RED, RESET);
        }
        break;
      case 'h':
      case 'H':
        printf("Uso: ./aula0905 <opcoes> <arquivos>\n");
        printf("Opcoes:\n");
        printf("  |-d| |-D| Converter arquivo de formato Unix para formato DOS\n");
        printf("  |-u| |-U| Converter arquivo de formato DOS para formato Unix\n");
        printf("  |-H| |-H| Exibir esta mensagem de uso\n");
        printf("  |-s| |-S| Exibir o conteudo do arquivo\n");
        exit(SUCESSO);
      case 's':
      case 'S':
        if (ExibirConteudoArquivo(optarg) == ok) {
          printf("%sConteudo do arquivo exibido com sucesso.\n%s", GREEN, RESET);
        } else {
            printf("%sErro ao exibir o conteudo do arquivo.\n%s", RED, RESET);
        }
        break;
      default:
        printf("Uso: ./aula0905 <opcoes> <arquivos>\n");
        printf("Opcoes:\n");
        printf("  |-d| |-D| Converter arquivo de formato Unix para formato DOS\n");
        printf("  |-u| |-U| Converter arquivo de formato DOS para formato Unix\n");
        printf("  |-H| |-H| Exibir esta mensagem de uso\n");
        printf("  |-s| |-S| Exibir o conteudo do arquivo\n");
        exit(FALHA);
        }
    }

    return SUCESSO;
}

/* $RCSfile$ */
