CC=gcc

all: pi_mutex.o 
	${CC} -pthread -o pi_mutex pi_mutex.o 
pi_mutex.o: pi_mutex.c
	${CC} -c pi_mutex.c
clean:
	rm -rf *.o pi_mutex 
