/*
	Physical memory allocator
*/

#ifndef KALLOC_H
# define KALLOC_H

# include <types.h>

# define KALLOC_MAX_PAGES 5

struct kalloc_ptr {
	void	*placement_address;
	size_t	size;
};

void	*kmalloc_int(size_t size, uint8_t align, uint32_t *phys);

void	*kmalloc(size_t size);
void	*kfree(void *ptr);


#endif
