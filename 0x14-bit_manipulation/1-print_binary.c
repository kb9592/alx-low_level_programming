#include "main.h"

/**
 * print_binary - a function to print the binary representation of a number
 * @n: the number to be used to print the binary number
 */

void print_binary(unsigned long int n)
{
	int ke, add = 0;
	unsigned long int num;

	for (ke = 63; ke >= 0; ke--)
	{
		num = n >> ke;
		if (num & 1)
		{
			_putchar('1');
			add++;
		}

		else if (num)
			_putchar('0');
	}

	if (!add)
		_putchar('0');
}
