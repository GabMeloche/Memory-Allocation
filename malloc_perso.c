#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "malloc_perso.h"

void* malloc_perso(size_t size)
{
	void* brkAdress = sbrk(size);
	return brkAdress;
}

void initialize_block(t_block* block)
{
	if (block == NULL)
		return;

	block->size = 0;
	block->next = NULL;
	block->previous = NULL;
	block->free = false;
}

void setBlock(t_block* block, int size, t_block* next, t_block* previous, bool free)
{
	block->size = size;
	block->next = next;
	block->previous = previous;
	block->free = free;
}

t_block* extend_heap(size_t size)
{
	t_block* result = NULL;

	printf("BRK before t_block allocation : %p\n", sbrk(0));
	result = sbrk(sizeof(t_block));
        printf("BRK after t_block allocation : %p\n", sbrk(0));

	initialize_block(result);

        printf("BRK before data allocation : %p\n", sbrk(0));
	sbrk(size);
        printf("BRK after t_block allocation : %p\n", sbrk(0));



	return result;
}
