#include <stdio.h>
#include "malloc_perso.h"
#include "free_perso.h"
#include <stdlib.h>
#include <limits.h>
int main()
{
	int* lele = malloc_perso(8);
	int* lolo = malloc_perso(sizeof(int) * 3);
	char* noix = malloc_perso(sizeof(char) * 10);
        char* peanut = malloc_perso(sizeof(char));
        int* lala = malloc_perso(sizeof(int) * 10);


	free_perso(lolo);

		
        printf("lele start: %p\n", (void*)lele);
        printf("lolo start: %p\n", (void*)lolo);
	printf("noix start: %p\n", (void*)noix);
	printf("peanut start: %p\n", (void*)peanut);
        printf("lala start: %p\n", (void*)lala);
        int* realign = malloc_perso(sizeof(int) * 1);
        printf("realign start: %p\n", (void*)realign);
		

//	printf("available block with %ld size: %p\n", block->size,(void*) block);	
}
