#include "main.h"

/**
 * binary_to_uint - a function that converts a
 * binary number to an unsigned int
 * @b: points to a string of 0 and 1 chars
 * Return: the converted number, or 0 if there
 * is one or more chars in the string b that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int bi_num = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		bi_num = bi_num * 2 + (*b++ - '0');
	}
	return (bi_num);
}
