#include "main.h"

/**
 * get_bit - a function that returns the
 * value of a bit at a given index
 * @n: the number to look for
 * @index: the index, starting from 0 of the bit
 * that needs to be gotten
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int numval;

	if (index >= sizeof(n) * 8)
		return (-1);

	numval = (n >> index) & 1;

	return (numval);
}
