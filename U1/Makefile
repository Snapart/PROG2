# Carola Berger
# Makefile


all: BeC-U1-1  BeC-U1-2  BeC-U1-3  BeC-U1-4

BeC-U1-1: BeC-U1-1.o
	gcc BeC-U1-1.o -o BeC-U1-1 -lm

BeC-U1-2: BeC-U1-2.o                   
	gcc BeC-U1-2.o -o BeC-U1-2 -lm
        
BeC-U1-3: BeC-U1-3.o                   
	gcc BeC-U1-3.o -o BeC-U1-3 -lm  

BeC-U1-4: BeC-U1-4.o                   
	gcc BeC-U1-4.o -o BeC-U1-4

BeC-U1-1.o: BeC-U1-1.c
	gcc -Wall -c BeC-U1-1.c -lm

BeC-U1-2.o: BeC-U1-2.c
	gcc -Wall -c BeC-U1-2.c -lm

BeC-U1-3.o: BeC-U1-3.c
	gcc -Wall -c BeC-U1-3.c -lm

BeC-U1-4.o: BeC-U1-4.c
	gcc -Wall -c BeC-U1-4.c

clean:
	rm *.o BeC-U1-1  BeC-U1-2  BeC-U1-3  BeC-U1-4

Abgabe:
	tar cvfz BeC-U1.tar.gz *.c Makefile
