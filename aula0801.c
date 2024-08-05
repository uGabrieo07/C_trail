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
#include <string.h>
#include "cores.h"
#include "aula0801.h"

tipoErros CodificarBase16(byte *bytes, ull numBytes, char *string) {
    if (numBytes == 0) {
        printf("\n%sO numero de bytes passado e zero%s\n", RED, RESET);
        return bytesZero;
    }

    us index, auxiliar, contador;
    byte quociente, restosDivisoes[2]; 

    for (index = 0; index < numBytes; index++) {
        auxiliar = 0;
        contador = 0;
        quociente = bytes[index];

        while (quociente != 0) {
            restosDivisoes[auxiliar] = quociente % 16;
            quociente /= 16;
            auxiliar++;
            contador++;
        }

        
        while (contador < 2) {
            restosDivisoes[auxiliar++] = 0;
            contador++;
        }

        for (auxiliar = 0; auxiliar < 2; auxiliar++) {
            
            if (restosDivisoes[auxiliar] < 10) {
                string[2 * index + (1 - auxiliar)] = '0' + restosDivisoes[auxiliar];
            } else {
                string[2 * index + (1 - auxiliar)] = 'A' + (restosDivisoes[auxiliar] - 10);
            }
        }
    }

    
    string[2 * numBytes] = '\0';

    

    return ok;
}


#include "aula0801.h"

tipoErros 
DecodificarBase16(char *string,byte *bytes, ull *numBytes) 

{
    if (string == NULL || bytes == NULL || numBytes == NULL) {
        return argumentoNulo;
    }

    ull comprimento = 0;
    while (string[comprimento] != '\0') {
        comprimento++;
    }

    if (comprimento % 2 != 0) {
        return comprimentoInvalido;
    }
		
		us auxiliar;
    
		for (auxiliar = 0; auxiliar < *numBytes; auxiliar++) {
        byte nibbleMaior, nibbleMenor;

        /* Converter o primeiro caractere (nibble maior) */
        if (string[2 * auxiliar] >= '0' && string[2 * auxiliar] <= '9') {
            nibbleMaior = string[2 * auxiliar] - '0';
        } else if (string[2 * auxiliar] >= 'A' && string[2 * auxiliar] <= 'F') {
            nibbleMaior = string[2 * auxiliar] - 'A' + 10;
        }else {
            return caractereInvalido;
        }

        /* Converter o segundo caractere (nibble menor) */
        if (string[2 * auxiliar + 1] >= '0' && string[2 * auxiliar + 1] <= '9') {
            nibbleMenor = string[2 * auxiliar + 1] - '0';
        } else if (string[2 * auxiliar + 1] >= 'A' && string[2 * auxiliar + 1] <= 'F') {
            nibbleMenor = string[2 * auxiliar + 1] - 'A' + 10;
        } else {
            return caractereInvalido;
        }

        bytes[auxiliar] = (nibbleMaior << 4) | nibbleMenor;
    }

    return ok;
}

tipoErros 
CodificarBase32(byte *bytes, ull numeroBytes, tipoAlfabetoBase32 tipoAlfabeto, char *saida) {
    if (bytes == NULL || saida == NULL) {
        return argumentoNulo;
    }

    if (numeroBytes == 0) {
        return bytesZero;
    }

    char *alfabetoBasico = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    char *alfabetoExtendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    char *alfabeto = (tipoAlfabeto == basico) ? alfabetoBasico : alfabetoExtendido;

    ull valor = 0;
		us auxiliar, bits = 0, index = 0;

    for ( auxiliar = 0; auxiliar < numeroBytes; auxiliar++) {
        valor = (valor << 8) | bytes[auxiliar];
        bits += 8;

        while (bits >= 5) {
            saida[index++] = alfabeto[(valor >> (bits - 5)) & 31];
            bits -= 5;
        }
    }

    if (bits > 0) {
        saida[index++] = alfabeto[(valor << (5 - bits)) & 31];
    }

    saida[index] = '\0';

    return ok;
}


tipoErros 
DecodificarBase32(char *string, byte *bytes, ull *numBytes, tipoAlfabetoBase32 tipoAlfabeto) {
    if (string == NULL || bytes == NULL || numBytes == NULL) {
        return argumentoNulo;
    }

    ull comprimento = 0;
    while (string[comprimento] != '\0') {
        comprimento++;
    }

    if (comprimento % 8 != 0) {
        return comprimentoInvalido;
    }

    char *alfabetoBasico = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    char *alfabetoExtendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    char *alfabeto = (tipoAlfabeto == basico) ? alfabetoBasico : alfabetoExtendido;

    ull valor = 0;
    us auxiliar, bits = 0, index = 0;
    for (auxiliar = 0; auxiliar < comprimento; auxiliar++) {
        char *posicao = strchr(alfabeto, string[auxiliar]);
        if (posicao == NULL) {
            return caractereInvalido;
        }
        valor = (valor << 5) | (posicao - alfabeto);
        bits += 5;

        if (bits >= 8) {
            bytes[index++] = (valor >> (bits - 8)) & 0xFF;
            bits -= 8;
        }
    }

    *numBytes = index;
    return ok;
}



tipoErros 
CodificarBase64(byte *bytes, ull numBytes, tipoFinalLinha finalLinha, tipoAlfabetoBase64 tipoAlfabeto, char *string) {

    char base64_alphabet_basic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char base64_alphabet_safe[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

    if (bytes == NULL || string == NULL) {
        return argumentoNulo;
    }

    if (numBytes == 0) {
        return bytesZero;
    }

    const char *alfabeto = (tipoAlfabeto == padrao) ? base64_alphabet_basic : base64_alphabet_safe;

    us auxiliar;
    char *saida = string;
    ull valor;
    us padding = 0;

    for (auxiliar = 0; auxiliar < numBytes; auxiliar += 3) {
        valor = bytes[auxiliar] << 16;
        if (auxiliar + 1 < numBytes) {
            valor |= bytes[auxiliar + 1] << 8;
        } else {
            padding++;
        }
        if (auxiliar + 2 < numBytes) {
            valor |= bytes[auxiliar + 2];
        } else {
            padding++;
        }

        saida[0] = alfabeto[(valor >> 18) & 0x3F];
        saida[1] = alfabeto[(valor >> 12) & 0x3F];
        saida[2] = (auxiliar + 1 < numBytes) ? alfabeto[(valor >> 6) & 0x3F] : '=';
        saida[3] = (auxiliar + 2 < numBytes) ? alfabeto[valor & 0x3F] : '=';

        saida += 4;
    }

    if (finalLinha == habilitado) {
        *saida++ = '\n';
    }

    *saida = '\0';

    return ok;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aula0801.h"



tipoErros 
DecodificarBase64(char *string, tipoFinalLinha finalLinha, tipoAlfabetoBase64 tipoAlfabeto, byte *bytes, ull *numBytes) {

    const char alfabeto_basico[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const char alfabeto_seguro[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

    if (string == NULL || bytes == NULL || numBytes == NULL) {
        return argumentoNulo;
    }

    ull comprimento = strlen(string);
    if (comprimento % 4 != 0) {
        return comprimentoInvalido;
    }

    const char *alfabeto = (tipoAlfabeto == padrao) ? alfabeto_basico : alfabeto_seguro;
    ull index = 0;
    us valor, auxiliar, auxiliar1;
    us padding = 0;

    for (auxiliar = 0; auxiliar < comprimento; auxiliar += 4) {
        valor = 0;
        for (auxiliar1 = 0; auxiliar1 < 4; auxiliar1++) {
            if (string[auxiliar + auxiliar1] == '=') {
                padding++;
                valor <<= 6;
            } else {
                char *posicao = strchr(alfabeto, string[auxiliar + auxiliar1]);
                if (posicao == NULL) {
                    return caractereInvalido;
                }
                valor = (valor << 6) | (posicao - alfabeto);
            }
        }

        if (padding < 2) {
            bytes[index++] = (valor >> 16) & 0xFF;
        }
        if (padding < 1) {
            bytes[index++] = (valor >> 8) & 0xFF;
        }
        if (padding == 0) {
            bytes[index++] = valor & 0xFF;
        }
    }

    *numBytes = index;
    return ok;
}


/* $RCSfile$ */
