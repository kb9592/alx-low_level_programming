#include "main.h"
/**
 * _abs - to compute the absolute value of an integer
 * @c: number to compute
 * Return: absolut value of a number or zero
 */
int _abs(int n)
{
	if (n < 0)
	{
		int abs_num;

		abs_num = n * -1;
		return (abs_num);
	}
	return (n);
}
