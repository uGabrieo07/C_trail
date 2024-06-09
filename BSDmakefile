# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e Computacao
# Prof. Marcelo Luiz Drummond Lanza
# EEL270 - Computacao II - 2024/1
#
# Descricao:
#
# $Author: gabriel.depaula $
# $Dates$
# $Log: BSDmakefile,v $
# Revision 1.14  2024/06/07 18:19:13  gabriel.depaula
# *** empty log message ***
#
# Revision 1.13  2024/05/27 18:37:36  gabriel.depaula
# *** empty log message ***
#
# Revision 1.12  2024/05/27 06:37:58  gabriel.depaula
# *** empty log message ***
#
# Revision 1.11  2024/05/26 02:43:04  gabriel.depaula
# add rotulos, metodos e macros relacionados a aula04
#
# Revision 1.10  2024/05/13 05:28:17  gabriel.depaula
# foram adicionados as macros, rotulos e metedos referentes a aula03
#
# Revision 1.9  2024/05/05 02:48:49  gabriel.depaula
# foram adicionados os metodos para criar todas as bibliotecas de uma vez, além da corre�cao de alguns erros
#
# Revision 1.8  2024/05/04 19:54:59  gabriel.depaula
# foram adicionadas todas as macros e rotulos referentes a aula02
#
# Revision 1.7  2024/05/04 01:57:54  gabriel.depaula
# foi adicionada a macro AULA02 contendo o executavel aula0201a, assim como os rrotulos aula02 e aula0201a
#
# Revision 1.6  2024/04/22 06:57:34  gabriel.depaula
# adicionada a macro da aqula0107 assim como seu rotulo
#
# Revision 1.5  2024/04/22 04:28:59  gabriel.depaula
# adicionada a macro para aula0106 e seu rotulo
#
# Revision 1.4  2024/04/21 23:23:13  gabriel.depaula
# foi adicionada a macro AULA0105OBJS referente ao arquivo objeto da aula0105.c, além do seu referido rotulo
#
# Revision 1.3  2024/04/20 21:58:12  gabriel.depaula
# foi adicionado o arquivo objeto da funcao cabecalho na macro AULA0104
#
# Revision 1.2  2024/04/20 07:38:18  gabriel.depaula
# adcionadas as macros e roulos da aula0104.
#
# Revision 1.1  2024/04/20 05:35:42  gabriel.depaula
# Initial revision
#
# Revision 1.2  2024/04/20 03:10:19  gabriel.depaula
# *** empty log message ***
#
# Revision 1.1  2024/04/20 01:51:45  gabriel.depaula
# Initial revision
#



# macro do sistema operacional
OS = 'uname -s'

# macro referente ao compilador de C 
CC = gcc

.ifdef CLANG
CC = clang
.endif

# macro que armazena o valor do compilador de C
LD = $(CC)


# dialeto selecionado e dialeto padrao
DIALECT = ansi
STANDARD = -ansi

# alteracao do dialeto no comando make
.ifdef C89
DIALECT = c89
STANDARD = -std=c89
.elif C90
DIALECt = c90
STANDARD = -std=c90
.elif C99
DIALECT = c99
STANDARD = -std=c99
.elif C11
DIALECT = c11
STANDARD = -std=c11
.endif

#
DEBUG =

.ifdef DEPURACAO
DEBUG = -DDPURACAO
.endif

CFLAGS = -Wall $(STANDARD) $(DEBUG)
LFLAGS = -Wall

# macro correspondente ao executavel aula0102
AULA01 = aula0102 aula0103 aula0104 aula0105 aula0106 aula0107

AULA02 = aula0202a aula0202b\
				 aula0202c aula0202d

AULA03 = aula0302a aula0302b\
				 aula0302c aula0302d

AULA04 = aula0402a aula0402b\
				 aula0402c aula0402d\
				 aula0404a aula0404b\
				 aula0404c aula0404d

AULA05 = aula0502 aula0503\
				 aula0504 aula0505\
				 aula0506 aula0507

LIBMATEMATICADOWHILE = libmatematica-dowhile.a

LIBMATEMATICARECURSAO = libmatematica-recursao.a

LIBMATEMATICAFOR = libmatematica-for.a

LIBMATEMATICAWHILE = libmatematica-while.a

LIBMATEMATICA = libmatematica.a

# macro dos arquivos objeto "aula0101.o" e "aula0102.o"
AULA0102OBJS = aula0101.o aula0102.o

AULA0103OBJS = aula0101.o aula0103.o

AULA0104OBJS = aula0101.o aula0104.o

AULA0105OBJS = aula0101.o aula0105.o

AULA0106OBJS = aula0101.o aula0106.o

AULA0107OBJS = aula0101.o aula0107.o

AULA0202AOBJS = aula0201a.o aula0202.o

AULA0202BOBJS = aula0201b.o aula0202.o

AULA0202COBJS = aula0201c.o aula0202.o

AULA0202DOBJS = aula0201d.o aula0202.o

AULA0302AOBJS = aula0301a.o aula0302.o

AULA0302BOBJS = aula0301b.o aula0302.o

AULA0302COBJS = aula0301c.o aula0302.o

AULA0302DOBJS = aula0301d.o aula0302.o

AULA0402AOBJS = aula0401a.o aula0402.o

AULA0402BOBJS = aula0401b.o aula0402.o

AULA0402COBJS = aula0401c.o aula0402.o

AULA0402DOBJS = aula0401d.o aula0402.o

AULA0404AOBJS = aula0403a.o aula0404.o

AULA0404BOBJS = aula0403b.o aula0404.o

AULA0404COBJS = aula0403c.o aula0404.o

AULA0404DOBJS = aula0403d.o aula0404.o

AULA0404EOBJS = aula0403e.o aula0404.o

AULA0502OBJS = aula0501.o aula0502.o

AULA0503OBJS = aula0501.o aula0503.o

AULA0504OBJS = aula0501.o aula0504.o

AULA0505OBJS = aula0501.o aula0505.o

AULA0506OBJS = aula0501.o aula0506.o

AULA0507OBJS = aula0501.o aula0507.o

LIBMATEMATICARECURSAOOBJS = aula0201a.o aula0301a.o aula0401a.o aula0403a.o

LIBMATEMATICADOWHILEOBJS = aula0201b.o aula0301b.o aula0401b.o aula0403b.o

LIBMATEMATICAFOROBJS = aula0201c.o aula0301c.o aula0401c.o aula0403c.o

LIBMATEMATICAWHILEOBJS = aula0201d.o aula0301d.o aula0401d.o aula0403d.o

LIBMATEMATICAOBJS = aula0501.o

# macro que contem o valor de AULA01
EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04) $(AULA05)


# macro vazia para as bibliotecas
LIBS = $(LIBMATEMATICARECURSAO) $(LIBMATEMATICADOWHILE) $(LIBMATEMATICAFOR) $(LIBMATEMATICAWHILE) $(LIBMATEMATICA)

libs: $(LIBS)

# macro referente aos executaveis e as bibliotecas
ALL = $(EXECS) $(LIBS)

# regra especifica para a compilacao de arquivos
.c.o:
	$(CC) $(CFLAGS) -c $<

# rotulo dos executaveis
aula01: $(AULA01)
aula02: $(AULA02)
aula03: $(AULA03)
aula04: $(AULA04)
aula05: $(AULA05)
# rotulo dos executaveis e da biblioteca
all: $(ALL)

# rotulo dos executaveis sem a biblioteca
execs: $(EXECS)

# cria os executaveis refrentes ao rotulo aula02
aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)
aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)
aula0104: $(AULA0104OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0104OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)
aula0105: $(AULA0105OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0105OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0106: $(AULA0106OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0106OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0107: $(AULA0107OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0107OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)



aula0404a: $(AULA0404AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404AOBJS) -lm -L. -lmatematica-recursao 
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0404b: $(AULA0404BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404BOBJS) -lm -L. -lmatematica-dowhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0404c: $(AULA0404COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404COBJS) -lm -L. -lmatematica-for
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)



aula0404d: $(AULA0404DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404DOBJS) -lm -L. -lmatematica-while
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0404e: $(AULA0404EOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404EOBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0502: $(AULA0502OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0503: $(AULA0503OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0504: $(AULA0504OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0504OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0505: $(AULA0505OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0505OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0506: $(AULA0506OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0506OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0507: $(AULA0507OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0507OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

libmatematica-recursao.a: $(LIBMATEMATICARECURSAOOBJS)
	ar -r -c $@ $(LIBMATEMATICARECURSAOOBJS)


libmatematica-dowhile.a: $(LIBMATEMATICADOWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICADOWHILEOBJS)


libmatematica-for.a: $(LIBMATEMATICAFOROBJS)
	ar -r -c $@ $(LIBMATEMATICAFOROBJS)


libmatematica-while.a: $(LIBMATEMATICAWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICAWHILEOBJS)

libmatematica.a: $(LIBMATEMATICAOBJS)
	ar -r -c $@ $(LIMATEMATICAOBJS)

# executa um dos rotulos abaixo caso necessario
.PHONY: clean-all clean clean-objs clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c89 clean-c90 clean-c99 clean-c11

clean-all:
	rm -f *.o $(ALL) *.core *-FreeBSD-* *-Linux-*
clean:
	rm -f *.o $(ALL) *.core
clean-objs:	
	rm -f *.o *.core
clean-bsd:
	rm -f *.o $(ALL) *-FreeBSD-* *.core
clean-linux:
	rm -f *.o $(ALL) *-Linux-* *.core
clean-gcc:
	rm -f *.o $(ALL) *-gcc-* *.core
clean-clang:
	rm -f *.o $(ALL) *-clang-* *.core
clean-ansi:
	rm -f *.o $(ALL) *-ansi-* *.core
clean-c89:
	rm -f *.o $(ALL) *-c89-* *.core
clean-c90:
	rm -f *.o $(ALL) *-c90-* *.core
clean-c99:
	rm -f *.o $(ALL) *-c99-* *.core
clean-c11:
	rm -f *.o $(ALL) *-c11-* *.core
# $RCSFile$

