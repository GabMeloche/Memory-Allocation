#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "malloc_perso.h"
#include "malloc_ifs.h"
#include "block_operations.h"

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
                return block;

        return block_checker(block->next, size);
}

void    split_block (t_block* b, size_t size)
{
        if (b == NULL)
                return;


        void* newDataAddress = (char*)b + size;
        t_block* metaData = extend_heap(sizeof(t_block));

        metaData->data_ptr = newDataAddress;
        b->next->previous = metaData;
        set_block(metaData, size, b->next, b, true);
        set_block(b, b->size - size, metaData, b->previous, false);

        return;
}

void    set_block(t_block* block, int size, t_block* next, t_block* previous, bool free)
{
	if (block == NULL)
		return;

        block->size = size;
        block->next = next;
        block->previous = previous;
        block->free = free;
}

void    initialize_block(t_block* block)
{
       /* if (block == NULL)
                return;
*/
        block->size = 0;
        block->next = NULL;
        block->previous = NULL;
        block->free = false;
        block->data_ptr = NULL;
}
