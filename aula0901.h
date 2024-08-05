
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

#ifndef _AULA09_
#define _AULA09_ "@(#)aula0901.h $Revision$"

/*definindo tipos*/
typedef unsigned char byte;
typedef unsigned short us;
typedef enum {
							ok,
							erroAbrirArquivo,
              erroLendoArquivo
} tipoErros;

/*prototipo de funcoes*/
tipoErros
ExibirConteudoArquivo (char * /* (arquivo a ser exibido) */);

tipoErros 
ConverterArquivoFormatoUnixParaFormatoDos (char *arquivoOrigem, char *arquivoDestino);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char * /* original */, char * /*convertido */);


#endif

/* $RCSfile$ */
