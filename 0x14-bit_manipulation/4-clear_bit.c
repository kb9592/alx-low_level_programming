#include "main.h"

/**
 * clear_bit - function sets the value of a bit to 0 at a given index
 * @n: point to the number that will be changed
 * @index: the index that will start from 0 of the bit which will be set
 * Return: 1 if it works and -1 if there is an error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	*n = (~(1UL << index) & *n);

	return (1);
}
