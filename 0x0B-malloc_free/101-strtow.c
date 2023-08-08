#include "main.h"
#include <stdlib.h>

/**
 * count_word - function to help count the
 * number of words in a string
 * @s: string to check
 * Return: numver of words
 */
int count_word(char *s)
{
	int flag, ct, wd;

	flag = 0;
	wd = 0;

	for (ct = 0; s[ct] != '\0'; ct++)
	{
		if (s[ct] == ' ')
			flag = 0;
		else
			if (flag == 0)
			{
				flag = 1;
				wd++;
			}
	}

	return (wd);
}
/**
 * **strtow - divides sting into 2
 * @str: string to be split
 * Return: a pointer to an array of strings (Success)
 * or NULL if fails
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, j = 0, len = 0, wrd, c = 0, begin, end;

	while (*(str + len))
		len++;

	wrd = count_word(str);

	if (wrd == 0)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (wrd + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *)malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (begin < end)
					*tmp++ = str[begin++];
				*tmp = '\0';

				matrix[j] = tmp - c;
				j++;
				c = 0;
			}
		}

		else if (c++ == 0)
			begin = i;
	}

	matrix[j] = NULL;
	return (matrix);
}
