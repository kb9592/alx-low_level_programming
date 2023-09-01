#include "main.h"

/**
 * get_endianness - a function that checks the endianness
 * Return: 0 if it is big endian, 1 if it is little endian
 */

int get_endianness(void)
{
	unsigned int k = 1;
	char *a = (char *) &k;

	return (*a);
}
