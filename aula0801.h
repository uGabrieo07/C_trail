
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

#ifndef _AULA08_
#define _AULA08_ "@(#)aula0801.h $Revision$"
#define MAX_NUMERO_BYTES					256
/*definindo tipos*/
typedef unsigned char byte;
typedef unsigned short us;
typedef unsigned long long ull;
typedef enum {
							ok,
							bytesZero,
							comprimentoInvalido,
							argumentoNulo,
							caractereInvalido
} tipoErros;
typedef enum {
							basico,
							extendido
} tipoAlfabetoBase32;
typedef enum {
    padrao,
    seguro
} tipoAlfabetoBase64;
typedef enum {
    desabilitado,
    habilitado
} tipoFinalLinha;

/*prototipo de funcoes*/
tipoErros
CodificarBase16 (
								 byte * /* bytes recebidos */,
								 ull /* numero de bytes recebidos */,
								 char * /* string correspondente aos bytes recebidos */
								);



tipoErros
DecodificarBase16 (
									char * /* (E) */,
									byte * /* (S) */,
									ull *  /* (S) */
									);

tipoErros
CodificarBase32 (byte * /* (E) */,
 								 ull /* (E) */,
 								 tipoAlfabetoBase32 /* (E) */,
 								 char * /* (S) */
								);

tipoErros
DecodificarBase32 (char * /* (E) */,
                   byte * /* (S) */,
                   ull *  /* (S) */,
                   tipoAlfabetoBase32 /* (E) */
                  );

tipoErros 
CodificarBase64(
								byte * /* (E) */,
								ull /* (E) */,
								tipoFinalLinha /* (E) */,
								tipoAlfabetoBase64 /* (E) */,
								char * /* (S) */
							 );

tipoErros
DecodificarBase64 (
										char * /* (E) */,
										tipoFinalLinha /* (E) */,
										tipoAlfabetoBase64 /* (E) */,
										byte * /* (S) */,
										unsigned long long * /* (S) */
									);





#endif

/* $RCSfile$ */
