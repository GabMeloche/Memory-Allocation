#ifndef __MALLOC_PERSO__
#define __MALLOC_PERSO__

#include <stdbool.h>

typedef struct s_block
{
	size_t size;
	struct s_block* next;
	struct s_block* previous;
	bool free;
} t_block;


void initialize_block(t_block* block);

t_block* extend_heap(size_t size);

void* malloc_perso(size_t size);

#endif
