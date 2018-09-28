#ifndef __MALLOC_IFS__
#define __MALLOC_IFS__

t_block* if_first_block(size_t size, t_block* newBlock);

t_block* if_not_first(size_t size, t_block* newBlock, t_block* lastBlock);

t_block* if_block_found(size_t size, t_block* newBlock);

#endif
