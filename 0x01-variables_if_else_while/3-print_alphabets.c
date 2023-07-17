#include <stdio.h>
/**
 * main - entry for a program that prints the alphabet in lowercase, and then in uppercase
 * Return: 0 (Success)
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z' || c <= 'Z')
	{
		putchar(c);
		c++;
		if (c > 'z')
		{
			c = 'A';
		}
	}
	putchar('\n');
	return (0);
}
