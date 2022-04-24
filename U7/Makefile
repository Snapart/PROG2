all: BeC-U7-1 BeC-U7-abgabe.tar.gz

BeC-U7-1.o: BeC-U7-1.c
	gcc -c -Wall BeC-U7-1.c -o BeC-U7-1.o

BeC-U7-1: BeC-U7-1.o
	gcc -Wall BeC-U7-1.o -o BeC-U7-1


BeC-U7-abgabe.tar.gz: Makefile BeC-U7-1.c
	tar czvf BeC-U7-abgabe.tar.gz BeC-U7-1.c Makefile

clean:
	rm *.o BeC-U7-1
