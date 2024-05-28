
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
 * $Author: gabriel.depaula $
 * $Date: 2024/05/13 03:45:53 $
 * $Log: aula0301.h,v $
 * Revision 1.1  2024/05/13 03:45:53  gabriel.depaula
 * Initial revision
 *
 *
 *******************************************************************************/

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#ifndef AULA0301
#define AULA0301 "@(#)aula0301.h $Revision: 1.1 $"
 
typedef unsigned long long ull;
typedef unsigned short us;

ull
CalcularTermoSerieFibonacci (us);
#endif 












/* $RCSfile: aula0301.h,v $ */
