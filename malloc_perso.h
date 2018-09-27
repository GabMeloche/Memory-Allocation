#ifndef __MALLOC_PERSO__
#define __MALLOC_PERSO__

#include <stdbool.h>

typedef struct s_block
{
	size_t size;
	struct s_block* next;
	struct s_block* previous;
	bool free;
	void* data_ptr;
} t_block;

void*	ptr_first_block;

void initialize_block(t_block* block);

t_block* extend_heap(size_t size);

void* malloc_perso(size_t size);

t_block* if_first_block(size_t size, t_block* newBlock);

t_block* if_block_found(size_t size, t_block* newBlock);

size_t dataOptimiser(size_t size);

void setBlock(t_block* block, int size, t_block* next, t_block* previous, bool free);

t_block* find_block(size_t size);

t_block* block_checker(t_block* block, size_t size);

void split_block (t_block* b, size_t size);

#endif
