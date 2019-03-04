#include <stdio.h>
#include "omp_repair.h"
#define SIZE 10
int main() {
  int a[SIZE], b[SIZE];
  int i, result = 0;

  for(i = 0; i < SIZE; i++) {
    a[i] = i;
    b[i] = 2 * i;
  }
#pragma omp parallel shared(a, b), private(i), reduction(+:result)
  {
#pragma omp for
    for(i = 0; i < SIZE; i++) {
      result += a[i] + b[i];
    }
  }

  printf("result = %d\n", result);
}
