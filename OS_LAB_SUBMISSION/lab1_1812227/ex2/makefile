CC=gcc

main: main.o sub.o sum.o
	${CC} main.o sub.o sum.o -o main
main.o: main.c sum.h sub.h
	${CC} -c main.c sum.h sub.h
sub.o: sub.c sub.h
	${CC} -c sub.c sub.h
sum.o: sum.c sum.h
	${CC} -c sum.c sum.h
clean:
	rm -rf *.o main
