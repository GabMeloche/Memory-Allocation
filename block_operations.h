#ifndef __BLOCK_OPERATIONS__
#define __BLOCK_OPERATIONS__

void set_block(t_block* block, int size, t_block* next, t_block* previous, bool free);

t_block* find_block(size_t size);

t_block* block_checker(t_block* block, size_t size);

void split_block (t_block* b, size_t size);

void initialize_block(t_block* block);

#endif
