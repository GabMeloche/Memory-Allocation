#include <stdio.h>
#include <unistd.h>
#include "free_perso.h"
#include "malloc_perso.h"

void	free_perso(void* ptr)
{
	if (ptr == NULL)
		return;

	t_block*	block = (t_block*) ptr;

	block->free = true;
}
