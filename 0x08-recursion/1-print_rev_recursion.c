#include "main.h"

/**
 * _print_rev_recursion -  prints string in a reversed manner
 * @s: the string to be reversed
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
