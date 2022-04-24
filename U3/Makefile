all: BeC-U3-1 BeC-U3-2 BeC-U3-3 BeC-U3-4 BeC-U3-5_32 BeC-U3-5_64 berger_ue3.tar.gz

BeC_RiverFkt.o: BeC_RiverFkt.c BeC_RiverFkt.h
	gcc -Wall -c BeC_RiverFkt.c -o BeC_RiverFkt.o

BeC-U3-1.o: BeC-U3-1.c
	gcc -Wall -c BeC-U3-1.c -o BeC-U3-1.o

BeC-U3-1: BeC-U3-1.o
	gcc -Wall BeC-U3-1.o -o BeC-U3-1

BeC-U3-2.o: BeC-U3-2.c
	gcc -Wall -c BeC-U3-2.c -o BeC-U3-2.o -lm

BeC-U3-2: BeC-U3-2.o
	gcc -Wall BeC-U3-2.o -o BeC-U3-2 -lm

BeC-U3-3.o: BeC-U3-3.c BeC_RiverFkt.h
	gcc -Wall -c BeC-U3-3.c -o BeC-U3-3.o

BeC-U3-3: BeC-U3-3.o BeC_RiverFkt.o
	gcc -Wall BeC-U3-3.o BeC_RiverFkt.o -o BeC-U3-3

BeC-U3-4.o: BeC-U3-4.c BeC_RiverFkt.h
	gcc -Wall -c BeC-U3-4.c -o BeC-U3-4.o

BeC-U3-4: BeC-U3-4.o BeC_RiverFkt.o
	gcc -Wall BeC-U3-4.o BeC_RiverFkt.o -o BeC-U3-4

BeC-U3-5_32.o: BeC-U3-5.c
	gcc -Wall -c BeC-U3-5.c -m32 -o BeC-U3-5_32.o

BeC-U3-5_64.o: BeC-U3-5.c
	gcc -Wall -c BeC-U3-5.c -m64 -o BeC-U3-5_64.o

BeC-U3-5_32: BeC-U3-5_32.o
	gcc -Wall -m32 BeC-U3-5_32.o -o BeC-U3-5_32

BeC-U3-5_64: BeC-U3-5_64.o
	gcc -Wall -m64 BeC-U3-5_64.o -o BeC-U3-5_64

berger_ue3.tar.gz: 
	tar cvzf berger_ue3.tar.gz BeC_RiverFkt.c  BeC_RiverFkt.h  BeC-U3-1.c  BeC-U3-2.c  BeC-U3-3.c  BeC-U3-4.c  BeC-U3-5.c  Makefile

clean:
	rm *.o BeC-U3-1 BeC-U3-2 BeC-U3-3 BeC-U3-4 BeC-U3-5_32 BeC-U3-5_64
