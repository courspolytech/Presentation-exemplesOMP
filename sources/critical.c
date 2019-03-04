#include <stdio.h>
#include "omp_repair.h"
int main() {
  int b = 0;
#pragma omp parallel shared(b)
  {
#pragma omp critical
    {
      int local; /* une variable locale au thread */
      local=b; /* recopie le contenu de la variable partagée localement */
      local++; /* incrémente la variable locale*/
      b=local; /* recopie le résulat dans la variable partagée*/
    }
  }
  printf("%d\n", b);
}
