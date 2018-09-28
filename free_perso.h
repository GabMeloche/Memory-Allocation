#ifndef __FREE_PERSO__
#define __FREE_PERSO__
#include "malloc_perso.h"

void	free_perso(void* ptr);

void    try_to_fusion(t_block* freeBlock);

void	destroy_block(t_block* block);

#endif
