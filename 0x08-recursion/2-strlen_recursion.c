#include "main.h"

/**
 * _strlen_recursion - prints the string length
 * @s: the string
 * Return: the length of the string as an int
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}
