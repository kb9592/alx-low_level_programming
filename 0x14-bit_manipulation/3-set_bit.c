#include "main.h"

/**
 * set_bit - a function that sets the value
 * of a bit to 1 at a given index
 * @n: this points to the number to be replaced
 * @index: the index that starts from 0 of the bit to be set
 * Return: 1 if it works or -1 if there is an error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
