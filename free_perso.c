#include <stdio.h>
#include <unistd.h>
#include "free_perso.h"
#include "malloc_perso.h"
#include "block_operations.h"

void	free_perso(void* ptr)
{
	if (ptr == NULL)
		return;

	t_block* block = (t_block*) ptr;

	block->free = true;

	try_to_fusion(block);

	ptr = NULL;
}

void	try_to_fusion(t_block* freeBlock)
{
	if (freeBlock == NULL)
		return;

	t_block* nextBlock = freeBlock->next;
	t_block* previousBlock = freeBlock->previous;

	if (nextBlock->free && previousBlock->free)
	{
		previousBlock->size += nextBlock->size + freeBlock->size + (2 * sizeof(t_block));
		nextBlock->next->previous = previousBlock;
		previousBlock->next = nextBlock->next;
		destroy_block(freeBlock);
		destroy_block(nextBlock);
	}
	else if (nextBlock->free)
	{
		freeBlock->size += nextBlock->size + sizeof(t_block);
		freeBlock->next = nextBlock->next;
		nextBlock->next->previous = freeBlock;
		destroy_block(nextBlock);
	}
	else if (previousBlock->free)
	{
		previousBlock->size += freeBlock->size + sizeof(t_block);
		previousBlock->next = freeBlock->next;
		freeBlock->next->previous = previousBlock;
		destroy_block(freeBlock);
	}
}

void	destroy_block(t_block* block)
{
	if (block == NULL)
		return;

	set_block(block, 0, NULL, NULL, false);
        block = NULL;
}
