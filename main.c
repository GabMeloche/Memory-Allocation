#include <stdio.h>
#include "malloc_perso.h"
#include "free_perso.h"
#include <stdlib.h>
#include <limits.h>

int main()
{
	int* lele = malloc_perso(8);
	int* lolo = malloc_perso(sizeof(int) * 8);
	char* noix = malloc_perso(sizeof(char) * 10);
        char* peanut = malloc_perso(sizeof(char));
        int* lala = malloc_perso(sizeof(int) * 10);
	free_perso(lolo);
	free_perso(peanut);
	free_perso(noix);
	int* realign = malloc_perso(sizeof(int) * 1);
}	
