#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "malloc_perso.h"
#include "malloc_ifs.h"
#include "block_operations.h"

t_block* if_first_block(size_t size, t_block* newBlock)
{
	if (newBlock == NULL)
		return NULL;

        newBlock = extend_heap(size);
        void* endOfBlock = sbrk(0);

        set_block(newBlock, size, endOfBlock, NULL, false);
        ptr_first_block = newBlock;

        return newBlock;
}

t_block* if_not_first(size_t size, t_block* newBlock, t_block* lastBlock)
{
	if (newBlock == NULL || lastBlock == NULL)
		return NULL;

        t_block* foundBlock = find_block(size);

        if (foundBlock != NULL)
                newBlock = if_block_found(size, newBlock);

        newBlock = extend_heap(size);
        void* endOfBlock = sbrk(0);
        set_block(newBlock, size, endOfBlock, lastBlock, false);

        return newBlock;
}

t_block* if_block_found(size_t size, t_block* newBlock)
{
	/*if (newBlock == NULL)
		return NULL;
*/
        t_block* foundBlock = find_block(size);

        if (foundBlock != NULL)
        {
               newBlock = foundBlock;

               if (foundBlock->size > size)
                        split_block(foundBlock, size);

               set_block(newBlock, newBlock->size, foundBlock->next, foundBlock->previous, false);
        }

     return newBlock;
}

