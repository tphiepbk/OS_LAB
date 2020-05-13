#include <stdio.h>
#include "sum.h"
#include "sub.h"

int main(int argc, char* argv[]) {
	int a, b;
	printf("Enter a : ");
	scanf("%d", &a);
	printf("Enter b : ");
	scanf("%d", &b);
	int resSum = sum(a,b);
	int resSub = sub(a,b);
	printf("a + b = %d\n", resSum);
	printf("a - b = %d\n", resSub);
	return 0;
}
