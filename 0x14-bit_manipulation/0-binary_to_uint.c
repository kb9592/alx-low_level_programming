#include "main.h"

/**
 * binary_to_unit - this function converts binary numbers
 * to an unsigned intiger
 * @b: this points to a string of 0 and 1 characters
 * Return: the converted number. Or 0 if there is more than one
 * characters in the string b, tha is not 0 or 1
 */

unsigned int binary_to_unit(const char *b)
{
	int u;
	unsigned int byn_num = 0;

	if (!b)
		return (0);

	for (u = 0; b[u]; u++)
	{
		if (b[u] < '0' || b[u] > '1')
			return (0);
		byn_num = 2 * byn_num + (b[u] - '0');
	}

	return (byn_num);
}
