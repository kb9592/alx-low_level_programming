#include "main.h"

/**
 * get_bit - a function to return the value of a bit of a given index
 * @n: the number to look for
 * @index: the index which starts from 0 of the bit needed
 * Return: the value of the bit at the index or -1 if there's an error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int numbval;

	if (index >= sizeof(n) * 8)
		return (-1);

	numbval = (n >> index) & 1;

	return (numbval);
}
