#include <stdio.h>
#include "omp_repair.h"
#define SIZE 20
int main() {
  int a[SIZE], b[SIZE], c[SIZE], i, tid;
  for(i = 0; i < SIZE; i++) {
    a[i] = i;
    b[i] = 2 * i;
  }
  #pragma omp parallel for shared(a, b, c) private(i, tid)
/* ajout des clauses directement au pragma et retrait du bloc {}*/
    for(i = 0; i < SIZE; i++) {
      c[i] = a[i] + b[i];
      tid = omp_get_thread_num();
      printf("Thread %d, i = %d\n", tid, i);
    }

  for(i = 0; i < SIZE; i++) printf("%d\n", c[i]);
}
