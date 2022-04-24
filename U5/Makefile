all: BeC-U5-1 BeC-U5-2 BeC-U5-abgabe.tar.gz

BeC-U5-1.o: BeC-U5-1.c
	gcc -c -Wall BeC-U5-1.c -o BeC-U5-1.o

BeC-U5-1: BeC-U5-1.o
	gcc -Wall BeC-U5-1.o -o BeC-U5-1

BeC-U5-2.o: BeC-U5-2.c
	gcc -c -Wall BeC-U5-2.c -o BeC-U5-2.o

BeC-U5-2: BeC-U5-2.o
	gcc -Wall BeC-U5-2.o -o BeC-U5-2

BeC-U5-abgabe.tar.gz: Makefile BeC-U5-2.c BeC-U5-1.c
	tar -cvjf BeC-U5-abgabe.tar.gz BeC-U5-2.c BeC-U5-1.c Makefile

clean:
	rm *.o BeC-U5-2 BeC-U5-1
