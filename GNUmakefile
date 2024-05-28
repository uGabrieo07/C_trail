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
# $Log: GNUmakefile,v $
# Revision 1.12  2024/05/27 18:37:36  gabriel.depaula
# *** empty log message ***
#
# Revision 1.11  2024/05/26 02:42:30  gabriel.depaula
# add rotulos, metodos e macros relacionadas a aula04
#
# Revision 1.10  2024/05/13 05:28:54  gabriel.depaula
# foram adicionados os rotulos, metodos e macros ralativos a aula03
#
# Revision 1.9  2024/05/05 02:49:34  gabriel.depaula
# foram adicionados alguns metodos relativos a cria√cao das biblioteca, al√©m da correcao de alguns bugs
#
# Revision 1.8  2024/05/04 19:55:51  gabriel.depaula
# foram adicionadas todas as macros e rotulos referentes a aula02
#
# Revision 1.7  2024/05/04 01:59:01  gabriel.depaula
# *** empty log message ***
#
# Revision 1.6  2024/04/22 06:57:56  gabriel.depaula
# adicionada a macro da aula0107 assim como seu rotulo
#
# Revision 1.5  2024/04/22 04:28:40  gabriel.depaula
# adicionada a macro para aula0106 e seu rotulo
#
# Revision 1.4  2024/04/21 23:24:04  gabriel.depaula
# foi adicionada a macro AULA0105OBJS referente ao arquivo objeto da aula0105.c, alem do seu referido rotulo
#
# Revision 1.3  2024/04/20 22:04:32  gabriel.depaula
# adicionado o arquivo objeto na macro AULA0104 para a funcao exibir cabecalho
#
# Revision 1.2  2024/04/20 07:39:15  gabriel.depaula
# adicionadas as macros e rotulos da aula0104 .
#
# Revision 1.1  2024/04/20 05:36:09  gabriel.depaula
# Initial revision
#
# Revision 1.1  2024/04/20 01:54:48  gabriel.depaula
# Initial revision
#



# macro do sistema operacional
OS = $(shell uname -s)

# macro referente ao compilador de C 
CC = gcc

ifeq ($(cc),CLANG)
CC = clang
endif

# macro que armazena o valor do compilador de C
LD = $(CC)


# macro que armazena o comando Wall que mostra todos os warnings da compilacao, mostra os DEBUGs e adiciona o dialeto padrao.
CFLAGS = -Wall $(STANDARD) $(DEBUG)


# macro referente ao comando Wall
LFLAGS = -Wall


# dialeto selecionado e dialeto padrao
DIALECT = ansi
STANDARD = -ansi

# alteracao do dialeto no comando make
ifeq ($(dialeto),c89)
DIALECT = c89
STANDARD = -std=c89
ifeq ($(dialeto),c90)
DIALECt = c90
STANDARD = -std=c90
ifeq ($(dialeto),c99)
DIALECT = c99
STANDARD = -std=c99
ifeq ($(dialeto),c11)
DIALECT = c11
STANDARD = -std=c11
endif

# macro correspondente ao executavel aula0102
AULA01 = aula0102 aula0103 aula0104

AULA02 = aula0202a aula0202b\
				 aula0202c aula0202d

AULA03 = aula0302a aula0302b\
				 aula0302c aula0302d

AULA04 = aula0402a aula0402b\
				 aula0402c aula0402d\
				 aula0404a aula0404b\
				 aula0404c aula0404d\
				 aula0404e

LIBMATEMATICARECURSAO = libmatematica-recursao.a

LIBMATEMATICADOWHILE = libmatematica-dowhile.a

LIBMATEMATICAFOR = libmatematica-for.a

LIBMATEMATICAWHILE = libmatematica-while.a

# macro dos arquivos objeto "aula0101.o" e "aula0102.o"
AULA0102OBJS = aula0101.o aula0102.o

AULA0103OBJS = aula0101.o aula0103.o

AULA0104OBJS = aula0101.o aula0104.o
# macro que contem o valor de AULA01

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

LIBMATEMATICARECURSAOOBJS = aula0201a.o aula0301a.o aula0401a.o aula0403a.o

LIBMATEMATICADOWHILEOBJS = aula0201b.o aula0301b.o aula0401b.o aula0403b.o

LIBMATEMATICAFOROBJS = aula0201c.o aula0301c.o aula0401c.o aula0403c.o

LIBMATEMATICAWHILEOBJS = aula0201d.o aula0301d.o aula0401d.o aula0403d.o


EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04)


# macro vazio para DEBUG
DEBUG = 

ifeq DEPURACAO
DEBUG = -DDEPURACAO
endif



# macro referente ao conteudo da macro AULA01, que deve armazenar um executavel
EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04)

# macro vazia para as bibliotecas
LIBS = $(LIBMATEMATICARECURSAO) $(LIBMATEMATICADOWHILE) $(LIBMATEMATICAFOR) $(LIBMATEMATICWHILE)

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
# rotulo dos executaveis e da biblioteca
all: $(ALL)

# rotulo dos executaveis sem a biblioteca
execs: $(EXECS)

# cria os executaveis refrentes ao rotulo aula02
aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(CC)-$(AULA0102OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)
aula0103: $(AULA0103OBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0103OBJS
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0104: $(AULA0104OBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0104OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0105: $(AULA0105OBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0105OBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0106: $(AULA0106OBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0106OBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0107: $(AULA0107OBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0107OBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0202a: $(AULA0202AOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0202AOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0202b: $(AULA0202BOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0202BOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0202c: $(AULA0202COBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0202COBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)



aula0202d: $(AULA0202DOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0202DOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0302a: $(AULA0302AOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0302AOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0302b: $(AULA0302BOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0302BOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0302c: $(AULA0302COBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0302COBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0302d: $(AULA0302DOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0302DOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0402a: $(AULA0402AOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0402AOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0402b: $(AULA0402BOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0402BOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0402c: $(AULA0402COBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0402COBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0402d: $(AULA0402DOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0402DOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)


aula0404a: $(AULA0404AOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0404AOBJS)
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT) -lm -L. -lmatematica-recursao


aula0404b: $(AULA0404BOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0404BOBJS) -lm -L. -lmatematica-dowhile
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0404c: $(AULA0404COBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0404COBJS) -lm -L. -lmatematica-for
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0404d: $(AULA0404DOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0404DOBJS) -lm -L. -lmatematica-while
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

aula0404e: $(AULA0404EOBJS)
	$(LD) $(CFLAGS) -o $@ $(CC)-$(AULA0404EOBJS) -lm
	cp -f $@ $@-$(OS)-$9(CC)-$(DIALECT)

libmatematica-recursao.a: $(LIBMATEMATICARECURSAOOBJS)
	ar -r -c $@ $(LIBMATEMATICARECURSAOOBJS)

libmatematica-dowhile.a: $(LIBMATEMATICADOWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICADOWHILEOBJS)

libmatematica-for.a: $(LIBMATEMATICAFOROBJS)
	ar -r -c $@ $(LIBMATEMATICAFOROBJS)

libmatematica-while.a: $(LIBMATEMATICAWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICAWHILEOBJS)


# executa um dos rotulos abaixo caso necessario
.PHONY: clean-all clean clean-objs clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c89 clean-c90 clean-c99 clean-c11

clean-all:
	rm -f $(ALL) *.o *.core *-FreeBSD-* *-Linux-*
clean:
	rm -f $(ALL) *.o *core
clean-objs:	
	rm -f *.o *.core
clean-bsd:
	rm -f $(ALL)*-FreeBSD-* *.core
clean-linux:
	rm -f $(ALL)*-Linux-* *.core
clean-gcc:
	rm -f $(ALL) *-gcc-* *.core
clean-clang:
	rm -f $(ALL) *-clang-* *.core
clean-ansi:
	rm -f $(ALL) *-ansi-* *.core
clean-c89:
	rm -f $(ALL) *-c89-* *.core
clean-c90:
	rm -f $(ALL) *-c90-* *.core
clean-c99:
	rm -f $(ALL) *-c99-* *.core
clean-c11:
	rm -f $(ALL) *-c11-* *.core
# $RCSFile$

