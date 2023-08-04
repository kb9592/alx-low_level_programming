#include "main.h"

/**
 * _memset - occupies a block of memory with a certain value
 * @s: the beginning of where the memory will occupy
 * @b: the wanted value
 * @n: the number of bytes to change
 * Return: change the array with a new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int k;

	for (k = 0; n > 0; k++)
	{
		s[k] = b;
		n--;
	}
	return (s);
}
