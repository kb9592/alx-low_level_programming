#include "main.h"

/**
 * _memcpy - is a function that copies the area of a memory
 * @dest: where the memory is stored
 * @src: where the memory is copied
 * @n: the number of bytes
 * Return: the copied memory with n byte changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int k = 0;
	int i = n;

	for (; k < i; k++)
	{
		dest[k] = src[k];
		n--;
	}
	return (dest);
}
