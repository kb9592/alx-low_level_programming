#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - assigns a memory using malloc
 * @b: the number of bytes to be allocated
 * Return: a pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
