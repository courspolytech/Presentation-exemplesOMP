#include <stdio.h>
#include "omp_repair.h"
int main(int argc, char *argv[]) {
int iam =0, np = 1;
#pragma omp parallel
	printf("Hello from one thread.\n");
}
