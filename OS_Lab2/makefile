CC=gcc

:mygrep
mygrep: main.o findsubstr.o readline.o
	${CC} main.o findsubstr.o readline.o -o mygrep
main.o: main.c findsubstr.h readline.h
	${CC} -c main.c findsubstr.h readline.h
findsubstr.o: findsubstr.c findsubstr.h
	${CC} -c findsubstr.c findsubstr.h
readline.o: readline.c readline.h
	${CC} -c readline.c readline.h
clean:
	rm -rf *.o mygrep
