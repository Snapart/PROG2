all: BeC-U6-1 BeC-U6-abgabe.tar.gz

BeC-U6-1.o: BeC-U6-1.c
	gcc -c -Wall BeC-U6-1.c -o BeC-U6-1.o

BeC-U6-1: BeC-U6-1.o
	gcc -Wall BeC-U6-1.o -o BeC-U6-1


BeC-U6-abgabe.tar.gz: Makefile BeC-U6-1.c
	tar czvf BeC-U6-abgabe.tar.gz BeC-U6-1.c Makefile

clean:
	rm *.o BeC-U6-1
