CC=gcc

:main
main: main.o ex1.o
	${CC} main.o ex1.o -o main
main.o: main.c ex1.h
	${CC} -c main.c ex1.h 
ex1.o: ex1.h ex1.c
	${CC} -c ex1.c ex1.h 
clean: 
	rm -rf *.o main
