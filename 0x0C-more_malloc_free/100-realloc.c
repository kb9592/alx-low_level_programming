#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: the pointer that points to the memory
 * initially allocated by malloc
 * @old_size: the size of the allocated memory for ptr
 * @new_size: the new size of the new memory block
 * Return: the pointer to the newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
	unsigned int n;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (n = 0; n < new_size; n++)
			ptr1[n] = old_ptr[n];
	}

	if (new_size > old_size)
	{
		for (n = 0; n < old_size; n++)
			ptr1[n] = old_ptr[n];
	}

	free(ptr);
	return (ptr1);
}
