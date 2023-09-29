#include "main.h"

/**
 * set_bit - this function sets the value of a bit to 1 at a given index
 * @n: this points to the number that will be replaced
 * @index: indicates the index that starts from 0 of the bit that will be set
 * Return: 1 if it works. Or -1 if fails
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
