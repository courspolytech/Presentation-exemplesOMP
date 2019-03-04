#include <stdio.h>
#include "omp_repair.h"
#define SIZE 20

int main(int argc, char *argv[])
{
  int i, TID;
  int n=SIZE, a[SIZE];
  #pragma omp parallel for default(none) ordered \
	schedule(runtime) private(i,TID) shared(n,a)
  for (i=0; i<n; i++)
	{
	TID = omp_get_thread_num();
	printf("Thread %d updates a[%d]\n",TID, i);
	a[i]+=i;

	#pragma omp ordered
	{printf("Thread %d prints value of a[%d] = %d\n",TID,i,a[i]);}
	}
  return 0;
}
