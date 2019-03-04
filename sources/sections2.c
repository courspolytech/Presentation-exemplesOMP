#include <stdio.h>
#include "omp_repair.h"
int main(int argc, char *argv[]) {

printf("Mon programme commence !\n");

#pragma omp parallel sections
{
#pragma omp section
	{
	printf("Mon premier thread %d sur %d.\n",omp_get_thread_num(), omp_get_num_threads());
	}

#pragma omp section
	{
	printf("Mon deuxième thread %d sur %d.\n",omp_get_thread_num(), omp_get_num_threads());
	}

/*printf("Mon dernier thread %d sur %d.\n",omp_get_thread_num(), omp_get_num_threads());*/
}

}
