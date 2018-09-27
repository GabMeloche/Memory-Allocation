#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "malloc_perso.h"

void* malloc_perso(size_t size)
{
	static int blockCounter = 0;
	static void* lastBlock = NULL;

	if (size == 0)
		return NULL;

	
	size = dataOptimiser(size);

	t_block* newBlock;

	
	if (blockCounter == 0)
	{
		newBlock = if_first_block(size, newBlock);
	}
	else
	{
		t_block* foundBlock = find_block(size);

		if (foundBlock != NULL)
		{
			newBlock = if_block_found(size, newBlock);
		}
                newBlock = extend_heap(size);
                void* endOfBlock = sbrk(0);
		setBlock(newBlock, size, endOfBlock, lastBlock, false);
	}
	newBlock->data_ptr = (char*) newBlock + sizeof(t_block);
	blockCounter++;
	lastBlock = newBlock;

	return newBlock;
}

t_block* if_first_block(size_t size, t_block* newBlock)
{
	newBlock = extend_heap(size);
	void* endOfBlock = sbrk(0);
        
	setBlock(newBlock, size, endOfBlock, NULL, false);
        ptr_first_block = newBlock;

	return newBlock;
}

t_block* if_block_found(size_t size, t_block* newBlock)
{
	t_block* foundBlock = find_block(size);

	if (foundBlock != NULL)
        {
 	       newBlock = foundBlock;
               setBlock(newBlock, newBlock->size, foundBlock->next, foundBlock->previous, false);
        
	       if (foundBlock->size > size)
               {
                        split_block(foundBlock, size);
               }
               return newBlock;
        }
        
     return newBlock; 

}
size_t	dataOptimiser(size_t size)
{
	if (size % 4 == 0)
		return size;

	return size + 4 - size % 4;
}

void initialize_block(t_block* block)
{
	if (block == NULL)
		return;

	block->size = 0;
	block->next = NULL;
	block->previous = NULL;
	block->free = false;
	block->data_ptr = NULL;
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

t_block* find_block(size_t size)
{
	t_block* block = block_checker(ptr_first_block, size);
	return block;
}

t_block* block_checker(t_block* block, size_t size)
{
	if (block == NULL)
		return NULL;
	
	if (block->size >= size && block->free == true)
	{
		return block;
	}


	return block_checker(block->next, size);
}

void split_block (t_block* b, size_t size)
{//SEG FAULT DUE TO B->NEXT NOT EXISTING
	if (b == NULL)
		return;
	void* newAddress = (char*)b + size;	
	t_block* newBlock = newAddress;

	initialize_block(newBlock);
	//newBlock = extend_heap(sizeof(t_block));
	
	setBlock(newBlock, b->size - size, b->next, b, true);
	b->next->previous = newBlock;
	b->next = newBlock;


	return;
}
