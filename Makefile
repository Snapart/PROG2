# Carola Berger
# Makefile


all: prog1

prog1: Prog1.o Berger.o Carola.o BergerCarolaBirth.o
	gcc -Wall Prog1.o Berger.o Carola.o BergerCarolaBirth.o -o Berger_Carola

Prog1.o: Prog1.c Berger.h Carola.h BergerCarolaBirth.h
	gcc -Wall -c Prog1.c

Berger.o: Berger.c Berger.h
	gcc -Wall -c Berger.c

Carola.o: Carola.c Carola.h
	gcc -Wall -c Carola.c

BergerCarolaBirth.o: BergerCarolaBirth.c BergerCarolaBirth.h
	gcc -Wall -c BergerCarolaBirth.c

clean:
	rm *.o Carola_Berger

Abgabe:
	tar cvfz abgabe.tar.gz *.c *.h Makefile

