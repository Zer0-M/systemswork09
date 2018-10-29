all : randgen.o
	gcc -o randtest randgen.o
randgen.o : randgen.c randgen.h
	gcc -c randgen.c
run :
	./randtest
clear :
	rm randtest
