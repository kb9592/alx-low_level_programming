#include <stdio.h>
/**
 * main - entry for a program that prints the lowercase alphabet in reverse
 * Return: 0 (Success)
 */
int main(void)
{
	int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
