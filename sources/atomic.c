#include <omp.h>
#include <stdio.h>
int main() {
int count = 0;
#pragma omp parallel shared(count)
{
  #pragma omp atomic
  //count = count + 1; //Not working?
  count++;
}
printf("%d\n", count);
}
