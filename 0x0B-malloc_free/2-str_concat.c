#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates 2 strings
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 * Return: a pointer to the newly allocated space in memory. NULL if fails.
 */
char *str_concat(char *s1, char *s2)
{
	int i, k, len1, len2, len3;
	char *output;

	len1 = len2 = 0;

	if (s1 != NULL)
	{
		i = 0;
		while (s1[i++] != '\0')
			len1++;
	}

	if (s2 != NULL)
	{
		i = 0;
		while (s2[i++] != '\0')
			len2++;
	}

	len3 = len1 + len2;
	output = (char *)malloc(sizeof(char) * (len3 + 1));
	if (output == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		output[i] = s1[i];
	for (k = 0; k < len2; k++, i++)
		output[i] = s2[k];
	output[len3] = '\0';

	return (output);
}
