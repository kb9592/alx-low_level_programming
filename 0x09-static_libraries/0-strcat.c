#include "main.h"

/**
 * _strcat - function which concatenates 2 strings
 * @dest: the entered value
 * @src: the entered value
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int k;
	int l;

	k = 0;
	while (dest[k] != '\0')
	{
		k++;
	}
	l = 0;
	while (src[l] != '\0')
	{
		dest[k] = src[l];
		k++;
		l++;
	}

	dest[k] = '\0';
	return (dest);
}
