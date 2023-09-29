#include "main.h"

/**
 * flip_bits - this function returns the number of bits needed to
 * flip to get from one number to another
 * @n: the initial number
 * @m: the other number
 * Return: the number of bits that have to be changed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int kab, count = 0;
	unsigned int add;
	unsigned long int new_num = n ^ m;

	for (kab = 63; kab >= 0; kab--)
	{
		add = new_num >> kab;
		if (add & 1)
			count++;
	}
	return (count);
}
