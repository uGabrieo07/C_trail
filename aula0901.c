
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

#ifdef __linux__
#define _XOPEN_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "aula0901.h"

tipoErros
ExibirConteudoArquivo (char *nomeArquivo)
{
    /* abre o arquivo a ser lido*/
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        return erroAbrirArquivo;
    }

    int offset = 0; /* Seta o offset inicial*/
    byte bytes[16]; /* Inicia a matriz que vai guardar os bytes lidos pela fread*/
    us bytesLidos; /* Guarda a quantidade de bytes lidos pela fread*/

		printf("\n");
	
    while ((bytesLidos = fread(bytes, sizeof(byte), 16, arquivo)) > 0) { /* Continua rondando se ao menos 1 byte  lido*/
       /*Exibir endereco hexadecimal do offset*/
        printf("%08X  ", offset); /*0--> preenche com zeros  esquerda; 8--> oito caracteres p/o campo; X--> hexadecimal*/

				printf("| ");

        /*Exibir bytes em hexadecimal*/
        us auxiliar;
        for (auxiliar = 0; auxiliar < bytesLidos; auxiliar++) {
            printf("%02X ", bytes[auxiliar]);
            if (auxiliar == 7) {
                printf(" ");
            }
        }

        /* Preencher espacos em branco se a linha tiver menos de 16 bytes */
        for (auxiliar = bytesLidos; auxiliar < 16; auxiliar++) {
            printf("   ");
        }

        /* Exibir caracteres imprimiveis */
        printf(" | ");
        for (auxiliar = 0; auxiliar < bytesLidos; auxiliar++) {
            if (bytes[auxiliar] >= 0x20 && bytes[auxiliar] <= 0x7E) { /* Se estiver entre 32 e 126 (em hexadecimal), entao corresponde
                                                                      a um caractere impreimivel*/
                printf("%c", bytes[auxiliar]);
            } else {
                printf(".");
            }
        }
        printf("\n");

        offset += 16;
    }

		printf("\n");

    if (ferror(arquivo)) {
        fclose(arquivo);
        return erroAbrirArquivo;
    }

    fclose(arquivo);
    return ok;
}

tipoErros 
ConverterArquivoFormatoUnixParaFormatoDos(char *arquivoOrigem, char *arquivoDestino) 
{
    /* Abre o arquivo de origem */
    FILE *origem = fopen(arquivoOrigem, "r");
    if (origem == NULL) {
        return erroAbrirArquivo;
    }

    /*Cria uma ponteiro para arquivo destino*/
    FILE *destino;
    char nomeTempDestino[256]; /* Inicializa o nome temporario do destino*/

    /* Se nao houver arquivo de destino, cria um temporario e cria um backup*/
    if (arquivoDestino == NULL) {
        strcpy(nomeTempDestino, "backup-XXXXXX");
        int resultadoTemp = mkstemp(nomeTempDestino);
        if (resultadoTemp == -1) {
            fclose(origem);
            return erroAbrirArquivo;
        }
        /*Abre o arquivo destino para escrita*/
        destino = fdopen(resultadoTemp, "w");
        if (destino == NULL) {
            fclose(origem);
            close(resultadoTemp);
            return erroAbrirArquivo;
        }

        
        time_t tempo = time(NULL);
        char buffer[256];
        strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&tempo));
        char nomeBackup[256];
        sprintf(nomeBackup, "backup-%s", buffer);

        if (rename(nomeTempDestino, nomeBackup) != 0) {
            fclose(origem);
            fclose(destino);
            return erroLendoArquivo;
        }
    } else {
        destino = fopen(arquivoDestino, "w");
        if (destino == NULL) {
            fclose(origem);
            return erroAbrirArquivo;
        }
    }

    int caractere;
    while ((caractere = fgetc(origem)) != EOF) {
        if (caractere == '\n') {
            if (fputc('\r', destino) == EOF) {
                fclose(origem);
                fclose(destino);
                return erroLendoArquivo;
            }
        }
        if (fputc(caractere, destino) == EOF) {
            fclose(origem);
            fclose(destino);
            return erroLendoArquivo;
        }
    }

    fcloseall();

		return ok;
}

tipoErros 
ConverterArquivoFormatoDosParaFormatoUnix(char *arquivoOrigem, char *arquivoDestino) {
    FILE *origem = fopen(arquivoOrigem, "r");
    if (origem == NULL) {
        return erroAbrirArquivo;
    }

    FILE *destino;
    char destinoTempName[256];

    if (arquivoDestino == NULL) {
        strcpy(destinoTempName, "backup-XXXXXX");
        int resultadoTemp = mkstemp(destinoTempName);
        if (resultadoTemp == -1) {
            fclose(origem);
            return erroAbrirArquivo;
        }
        destino = fdopen(resultadoTemp, "w");
        if (destino == NULL) {
            fclose(origem);
            close(resultadoTemp);
            return erroAbrirArquivo;
        }

        time_t t = time(NULL);
        char buffer[256];
        strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&t));
        char backupName[256];
        sprintf(backupName, "backup-%s", buffer);

        if (rename(destinoTempName, backupName) != 0) {
            fclose(origem);
            fclose(destino);
            return erroLendoArquivo;
        }
    } else {
        destino = fopen(arquivoDestino, "w");
        if (destino == NULL) {
            fclose(origem);
            return erroAbrirArquivo;
        }
    }

    int caractere;
    int caractereAnterior = 0;
    while ((caractere = fgetc(origem)) != EOF) {
        if (caractereAnterior == '\r' && caractere != '\n') {
            if (fputc('\n', destino) == EOF) {
                fclose(origem);
                fclose(destino);
                return erroLendoArquivo;
            }
        }
        if (caractere != '\r') {
            if (fputc(caractere, destino) == EOF) {
                fclose(origem);
                fclose(destino);
                return erroLendoArquivo;
            }
        }
        caractereAnterior = caractere;
    }

    if (caractereAnterior == '\r') {
        if (fputc('\n', destino) == EOF) {
            fclose(origem);
            fclose(destino);
            return erroLendoArquivo;
        }
    }

    fcloseall();

    return ok;
}
/* $RCSfile$ */
