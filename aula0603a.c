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

#define _XOPEN_SOURCE 1000
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include "cores.h"
#include "aula0601.h"

#define NUMERO_ARGUMENTOS 2
#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define BASE_INVALIDA 2
#define TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO 3
#define DIMENSAO_INVALIDA 4
#define DIGITO_NEGATIVO_INVALIDO 5
#define DIGITO_RG_INVALIDO 6
#define TAMANHO_EXTRAPOLADO 7
#define DIG_VER_VALIDO 8
#define DIG_VER_INV 9
#define END_OF_STRING '\0'

int
main (int argc, char *argv []) 
{
    byte indice, indiceDigito = 0;
    byte digito;
    byte validacao;
    char *verificacaoDigitos;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf("%s\nUso: %s <oito_primeiros_digitos_rg>%s \n", RED, argv[0], RESET);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    for (indice = 1; indice < argc; indice++)
    {
        if (argv[indice][0] == '-')
        {
            printf("%s\nO numero do Registro Geral nao pode conter digitos negativos.%s\n", RED, RESET);
            exit(DIGITO_NEGATIVO_INVALIDO);
        }
    }

    byte rg[9];

    for (indice = 0; indice < 10 && indiceDigito < 8; indice++)
    {
        if (argv[1][indice] == '.')
        {
            continue;
        }

        digito = (byte) argv[1][indice] - '0';

        if (digito < 0 || digito > 9)
        {
            printf("%s\nDigito invalido: (%c)%s\n", RED, argv[1][indice], RESET);
            exit(DIGITO_RG_INVALIDO);
        }

        rg[indiceDigito++] = digito;
    }

    if (errno == EINVAL)
    {
        printf("%s\nBase invalida.%s", RED, RESET);
        exit(BASE_INVALIDA);
    }

    if (errno == ERANGE)
    {
        printf("%s\nValor maximo do tipo unsigned char ou unsigned short foram excedidos.\n%s", RED, RESET);
        exit(TAMANHO_MAXIMO_ARGUMENTO_EXCEDIDO);
    }

    byte digitoVerificador = GerarDigitosVerificadoresRg(rg);

    rg[8] = digitoVerificador;

    validacao = (ValidarRg(rg) == ok) ? DIG_VER_VALIDO : DIG_VER_INV;

    printf("\nRG: ");
    for (indice = 0; indice < 8; indice++)
    {
        if (indice == 2 || indice == 5)
        {
            printf(".%u", rg[indice]);
        }
        else
        {
            printf("%u", rg[indice]);
        }
    }

    printf("-%u (%s)\n", rg[8], (validacao == DIG_VER_VALIDO) ? "Valido" : "Invalido");

    return SUCESSO;
}

/* $RCSfile$ */
