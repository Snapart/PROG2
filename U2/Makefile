# BeC-U2-4.c  date_help.c  date_help.h  date_help.o  Makefile

all: BeC-U2-1 BeC-U2-2 BeC-U2-3 BeC-U2-4 berger_ue2.tar.gz

date_help.o: date_help.c date_help.h
	gcc -Wall -c date_help.c -o date_help.o

BeC-U2-1.o: BeC-U2-1.c date_help.h
	gcc -Wall -c BeC-U2-1.c -o BeC-U2-1.o

BeC-U2-1: BeC-U2-1.o date_help.o
	gcc -Wall BeC-U2-1.o date_help.o -o BeC-U2-1

BeC-U2-2.o: BeC-U2-2.c
	gcc -Wall -c BeC-U2-2.c -o BeC-U2-2.o

BeC-U2-2: BeC-U2-2.o
	gcc -Wall BeC-U2-2.o -o BeC-U2-2 -lm

BeC-U2-3.o: BeC-U2-3.c date_help.h
	gcc -Wall -c BeC-U2-3.c -o BeC-U2-3.o

BeC-U2-3: BeC-U2-3.o date_help.o
	gcc -Wall BeC-U2-3.o date_help.o -o BeC-U2-3

BeC-U2-4.o: BeC-U2-4.c
	gcc -Wall -c BeC-U2-4.c -o BeC-U2-4.o

BeC-U2-4: BeC-U2-4.o
	gcc -Wall BeC-U2-4.o -o BeC-U2-4

berger_ue2.tar.gz: BeC-U2-1.c BeC-U2-2.c BeC-U2-3.c BeC-U2-4.c date_help.c date_help.h Makefile
	tar cvzf berger_ue2.tar.gz BeC-U2-1.c BeC-U2-2.c BeC-U2-3.c BeC-U2-4.c date_help.c date_help.h Makefile

clean:
	rm BeC-U2-1 BeC-U2-2 BeC-U2-3 BeC-U2-4 *.o
