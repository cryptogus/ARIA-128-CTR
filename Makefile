#Makefile

all: ARIA-128-CTR



ARIA-128-CTR: ARIA.o CTR.o main.o
	gcc -o ARIA-128-CTR ARIA.o CTR.o main.o

main.o: CTR.h main.c

ARIA.o:  ARIA.c

CTR.o: ARIA.h CTR.c

clean:
	rm -f ARIA-128-CTR
	rm -f *.o