#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "malloc_perso.h"
#include "malloc_ifs.h"
#include "block_operations.h"

void*	malloc_perso(size_t size)
{
	static int blockCounter = 0;
	static void* lastBlock = NULL;

	if (size == 0)
		return NULL;
	
	size = data_optimiser(size);

	t_block* newBlock = NULL;

	if (blockCounter == 0)
		newBlock = if_first_block(size, newBlock);
	else
		newBlock = if_not_first(size, newBlock, lastBlock);

	newBlock->data_ptr = (char*) newBlock + sizeof(t_block);
	blockCounter++;
	lastBlock = newBlock;

	return newBlock;
}

size_t	data_optimiser(size_t size)
{
	if (size % 4 == 0)
		return size;

	return size + 4 - size % 4;
}

t_block* extend_heap(size_t size)
{
	int allocSuccess = 0;
        void* break_ptr = sbrk(0);
	t_block* result = break_ptr;
	
	allocSuccess = brk((char*) break_ptr + sizeof(t_block));

	if (allocSuccess != 0)
		return NULL;
	
	initialize_block(result);
	break_ptr = sbrk(0);

	allocSuccess = brk((char*) break_ptr + size);

	if (allocSuccess != 0)
                return NULL;
        
	return result;
}

