all: BeC-U4-1 BeC-U4-2 BeC-U4-3 berger_ue3.tar.gz


BeC-U4-1.o: BeC-U4-1.c
	gcc -Wall -c BeC-U4-1.c -o BeC-U4-1.o

BeC-U4-1: BeC-U4-1.o
	gcc -Wall BeC-U4-1.o -o BeC-U4-1

BeC-U4-2.o: BeC-U4-2.c
	gcc -Wall -c BeC-U4-2.c -o BeC-U4-2.o

BeC-U4-2: BeC-U4-2.o
	gcc -Wall BeC-U4-2.o -o BeC-U4-2

BeC-U4-3.o: BeC-U4-3.c
	gcc -Wall -c BeC-U4-3.c -o BeC-U4-3.o

BeC-U4-3: BeC-U4-3.o 
	gcc -Wall BeC-U4-3.o -o BeC-U4-3

berger_ue3.tar.gz: 
	tar cvzf berger_ue4.tar.gz  BeC-U4-1.c  BeC-U4-2.c  BeC-U4-3.c  Makefile

clean:
	rm *.o BeC-U4-1 BeC-U4-2 BeC-U4-3
