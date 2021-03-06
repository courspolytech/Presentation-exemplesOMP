#include <stdio.h>
#include "omp_repair.h"
#define SIZE 10
int main() {
int a,i,n=SIZE, b[SIZE];
#pragma omp parallel shared(a,b) private(i)
{
  #pragma omp single
  {
    a = 10;
    printf("Single construct executed by thread %d\n",
        omp_get_thread_num());
  }
  /* A barrier is automatically inserted here */
  #pragma omp for
  for (i=0; i<n; i++)
    b[i] = a;
} /*-- End of parallel region --*/
printf("After the parallel region:\n");
for (i=0; i<n; i++)
  printf("b[%d] = %d\n",i,b[i]);
}
