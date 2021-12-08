CC=gcc
FLAGS=-Wall -g

all: libclassalgo.a stringProg

libclassalgo.a: algo.o
	$(AR) -rcs libclassalgo.a algo.o

algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c
main.o: main.c algo.h
	$(CC) $(FLAGS) -c main.c

stringProg: main.o libclassalgo.a
	$(CC) $(FLAGS) -o stringProg main.o libclassalgo.a


.PHONY: clean all

clean:
	rm -f *.o *.a stringProg
