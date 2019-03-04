#include <stdio.h>
#include "omp_repair.h"
int main(int argc, char *argv[]) {
  int b = 0;
#pragma omp parallel shared(b)
  {
        b++;
	printf("Incrementation par thread %d de %d \n", omp_get_thread_num(), omp_get_num_threads());
  }
  printf("Valeur finale : %d\n", b);
}
