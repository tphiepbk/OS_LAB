CC=gcc

all: pi_serial.o pi_multi-thread.o
	${CC} -pthread -o pi_serial pi_serial.o 
	${CC} -pthread -o pi_multi-thread pi_multi-thread.o 
pi_serial.o: pi_serial.c
	${CC} -c pi_serial.c
pi_multi-thread.o: pi_multi-thread.c
	${CC} -c pi_multi-thread.c
clean:
	rm -rf *.o pi_serial pi_multi-thread
