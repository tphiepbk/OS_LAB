CC=gcc

all: code.o
	${CC} -pthread -o code code.o
code.o: code.c
	${CC} -c code.c 
clean:
	rm -rf *.o code
	
