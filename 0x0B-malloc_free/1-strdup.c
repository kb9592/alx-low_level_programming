#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - allocates and copies to a new memory space location
 * @str: the string source
 * Return: 0
 */

char *_strdup(char *str)
{
	char *new;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	new = malloc(sizeof(char) * (i + 1));

	if (new == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		new[r] = str[r];
	return (new);
}
