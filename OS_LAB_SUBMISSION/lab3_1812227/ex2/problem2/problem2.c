#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	fork();
	fork();
	fork();
	getchar();
}
