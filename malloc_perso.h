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

t_block* extend_heap(size_t size);

void* malloc_perso(size_t size);

size_t data_optimiser(size_t size);

#endif
