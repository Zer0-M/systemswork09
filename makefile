all : randgen.o
	gcc -o randtest randgen.o
randgen.o : randgen.c
	gcc -c randgen.c
run :
	./randtest