#include "main.h"
/**
 * char *_strcpy - copies the string pointed to
 * @dest: to copy to
 * @src: to copy from
 * Return: string value
 */
char *_strcpy(char *dest, char *src)
{
	int c = 0;
	int d = 0;

	while (*(src + c) != '\0')
	{
		c++;
	}
	for (; d < c; d++)
	{
		dest[d] = src[d];
	}
	dest[c] = '\0';
	return (dest);
}
