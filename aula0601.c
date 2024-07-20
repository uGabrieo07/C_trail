
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
#include "aula0601.h"
#include "cores.h"


tiposErros
GerarDigitosVerificadoresRg (byte primeirosDigitosRg [8])
{
	byte indice;
	byte soma;
	byte restoDaDivisao;
	byte peso = 2;
	byte digitoVerificador;
	byte diferenca;

	for (indice = 0; indice < TAMANHO_MAXIMO_RG; indice++){
		soma += primeirosDigitosRg [indice] * peso;
		peso++;
	}	

	restoDaDivisao = soma % 11;
	diferenca = 11 - restoDaDivisao;

	if (diferenca == 11){
		digitoVerificador = 0;
		return digitoVerificador;
	} 
	
	if (diferenca == 10){
		digitoVerificador = 'X';
		return digitoVerificador;
	}

	digitoVerificador = diferenca;
	return digitoVerificador;
	
}


tiposErros
ValidarRg (byte rg[9])
{
	byte rgSemDigitoVerificador[7];
	byte digitoVerificadorReal;
	byte digitoVerificadorPassado = rg [8];
	byte indice;

	for (indice = 0; indice < 8; indice++){
		rgSemDigitoVerificador[indice] = rg[indice];
	} 
	
	digitoVerificadorReal = GerarDigitosVerificadoresRg (rgSemDigitoVerificador);
	
	if (digitoVerificadorPassado == digitoVerificadorReal){
		return ok;
	}
	
	return rgInvalido;

}









/* $RCSfile$ */
