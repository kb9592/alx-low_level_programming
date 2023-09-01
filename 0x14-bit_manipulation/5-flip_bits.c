#include "main.h"

/**
 * flip_bits - a function that returns the number of bits
 * needed to flip to get from one number to another
 * @n: the initial number
 * @m: the other number
 * Return: the number of bits to be changed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int k, count = 0;
	unsigned int add;
	unsigned long int new = n ^ m;

	for (k = 63; k >= 0; k--)
	{
		if (add & 1)
			count++;

		add = new >> k;
	}
	return (count);
}
