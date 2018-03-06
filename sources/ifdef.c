/*illustration de l'usage de la variable d'environnement pour la compilation */

#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif
#include<stdio.h>

int main(int argc, char *argv[]) {
#pragma omp parallel 
	{
	int TID=omp_get_thread_num();
	printf("%d\n",TID);
	}
}
