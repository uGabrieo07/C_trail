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
#include <string.h>
#include <getopt.h>
#include "cores.h"
#include "aula0901.h"

#define SUCESSO                                      0
#define FALHA                                        1
#define NUMERO_ARGUMENTOS_INVALIDO                   2

int 
main(int argc, char *argv[])
{
    int opt;
    int opcaoIndex = 0;
    char *input = NULL;
    char *output = NULL;

    struct option opcoesLongas[] = {
        {"dos", no_argument, 0, 'd'},
        {"help", no_argument, 0, 'h'},
        {"show", no_argument, 0, 's'},
        {"unix", no_argument, 0, 'u'},
    };

    if (argc < 2) {
        printf("Uso: ./aula0907 <opcoes> <arquivos>\n");
        printf("Opcoes:\n");
        printf("  |-d| |-D| |--dos|  Converter arquivo de formato Unix para formato DOS\n");
        printf("  |-u| |-U| |--unix| Converter arquivo de formato DOS para formato Unix\n");
        printf("  |-H| |-H| |--help| Exibir esta mensagem de uso\n");
        printf("  |-s| |-S| |--show| Exibir o conteudo do arquivo\n");
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    while ((opt = getopt_long(argc, argv, "dDhHSsUu", opcoesLongas, &opcaoIndex)) != -1) {
        switch (opt) {
            case 'd':
            case 'D':
                if (optind < argc) {
                    input = argv[optind++];
                    output = argv[optind++];
                }
                if (input && output) {
                    if (ConverterArquivoFormatoUnixParaFormatoDos(input, output) != ok) {
                        printf("%sErro ao converter arquivo de Unix para DOS.\n%s", RED, RESET);
                        exit(FALHA);
                    }
                } else {
                    printf("%sFaltando argumentos para a conversao de Unix %s\n", RED, RESET);
                    exit(FALHA);
                }
                break;
            case 'h':
            case 'H':
              printf("Uso: ./aula0907 <opcoes> <arquivos>\n");
              printf("Opcoes:\n");
              printf("  |-d| |-D| |--dos|  Converter arquivo de formato Unix para formato DOS\n");
              printf("  |-u| |-U| |--unix| Converter arquivo de formato DOS para formato Unix\n");
              printf("  |-H| |-H| |--help| Exibir esta mensagem de uso\n");
              printf("  |-s| |-S| |--show| Exibir o conteudo do arquivo\n");
                return 0;
            case 's':
            case 'S':
                if (optind < argc) {
                    input = argv[optind++];
                }
                if (input) {
                    if (ExibirConteudoArquivo(input) != ok) {
                        printf("%sErro ao exibir conteudo do arquivo.\n%s" , RED, RESET );
                        exit(FALHA);
                    }
                } else {
                    printf("%sFaltando argumento para exibicao do arquivo.\n%s", RED, RESET);
                    exit(FALHA);
                }
                break;
            case 'u':
            case 'U':
                if (optind < argc) {
                    input = argv[optind++];
                    output = argv[optind++];
                }
                if (input && output) {
                    if (ConverterArquivoFormatoDosParaFormatoUnix(input, output) != ok) {
                        printf("%sErro ao converter arquivo de DOS para Unix.\n%s", RED, RESET);
                        exit(FALHA);
                    }
                } else {
                    printf("%sFaltando argumentos para a conversao de DOS para Unix\n%s", RED, RESET);
                    exit(FALHA);
                }
                break;
            default:
              printf("Uso: ./aula0907 <opcoes> <arquivos>\n");
              printf("Opcoes:\n");
              printf("  |-d| |-D| |--dos|  Converter arquivo de formato Unix para formato DOS\n");
              printf("  |-u| |-U| |--unix| Converter arquivo de formato DOS para formato Unix\n");
              printf("  |-H| |-H| |--help| Exibir esta mensagem de uso\n");
              printf("  |-s| |-S| |--show| Exibir o conteudo do arquivo\n");
              exit(FALHA);
        }
    }

    return SUCESSO;
}

/* $RCSfile$ */
