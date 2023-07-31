#include "main.h"

/**
 * *_strchr - Locates a character in a string.
 * @s: the string to be searched
 * @c: the character to be located
 * Return: a pointer to the first occurence if c is found.
 * null if c is not found
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] >= '\0'; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return ('\0');
}
