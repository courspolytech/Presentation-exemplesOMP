#include <stdio.h>
#include "omp_repair.h"
#define SIZE 20
int main() {
  int i,a, n=SIZE;
#pragma omp parallel for private(i) lastprivate(a)
  for (i=0; i<n; i++)
  {
    a = i+1;
    printf("Thread %d a = %d i = %d\n", omp_get_thread_num(),a,i);
  }
printf("Value of a after parallel for: a = %d\n",a);
}
