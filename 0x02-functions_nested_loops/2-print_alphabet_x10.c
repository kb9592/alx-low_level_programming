#include "main.h"
/**
 * print_alphabet_x10 - prints 10 times the alphabet in lowercase
 */
void print_alphabet_x10(void)
{
	char alph;
	int n;

	n = 0;

	while (n < 10)
	{
		alph = 'a';
		while (alph <= 'z')
		{
			_putchar(alph);
			alph++;
		}
		_putchar('\n');
		n++;
	}
}
