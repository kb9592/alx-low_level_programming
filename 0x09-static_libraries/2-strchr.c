#include "main.h"
/**
 * _strchr - entry point
 * @s: value entered
 * @c: value entered
 * Return: 0 (Success)
 */
char *_strchr(char *s, char c)
{
	int k = 0;

	for (; s[k] >= '\0'; k++)
	{
		if (s[k] == c)
			return (&s[k]);
	}
	return (0);
}
