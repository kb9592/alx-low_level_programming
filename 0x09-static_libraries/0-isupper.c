#include "main.h"

/**
 * _isupper - to check for uppercase letters
 * @c: the char to check
 * Return: 1 if it is uppercase. 0 if it is not.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
