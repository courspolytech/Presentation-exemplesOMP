#include <stdio.h>
#include "omp_repair.h"
int main() {
  int b = 20, tid = 0;
#pragma omp parallel private(tid) firstprivate(b)
  {
    b++;
    tid = omp_get_thread_num();
    printf("Thread %d: b = %d\n", tid, b);
  }
  printf("b = %d\n", b);
}
