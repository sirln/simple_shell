#include "ash.h"

/**
  *ash_memcpy - copies memory area.
  *
  *@dest: parameter
  *@src: parameter
  *@size: parameter
  *
  *Return: copy of memory
  *
  */
void *ash_memcpy(char *dest, char *src, size_t size)
{
	size_t l = 0;

	while (l < size)
	{
		dest[l] = src[l];
		l++;
	}
	return (dest);
}


/**
 *ash_realloc - reallocates a memory block
 *
 *@ptr: pointer to  memory block
 *@size: size to reallocate
 *
 *Return: pointer to new memory block
 */
void *ash_realloc(void *ptr, size_t size)
{
	memory_block *block;
	void *new_ptr;
	size_t original_size, copy_size;

	if (!ptr)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	block = (memory_block *)((char *)ptr - sizeof(size_t));
	original_size = block->size;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);

	copy_size = (size < original_size) ? size : original_size - sizeof(size_t);
	ash_memcpy(new_ptr, ptr, copy_size);
	free(ptr);

	return (new_ptr);
}
