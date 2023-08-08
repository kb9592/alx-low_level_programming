#include "main.h"
#include <stdlib.h>

/**
 * argstostr - a function that concatenates all the arguments of your program
 * @ac: arguments count
 * @av: arguments vector
 * Return: a pointer to a new string. NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str, *s;
	int n, m, k, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (n = 0; n < ac; n++)
	{
		s = av[n];
		m = 0;

		while (s[m++])
			len++;
		len++;
	}

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	for (n = 0, m = 0; n < ac && m < len; n++)
	{
		s = av[n];
		k = 0;

		while (s[k])
		{
			str[m] = s[k];
			k++;
			m++;
		}
		str[m++] = '\n';
	}
	str[m] = '\0';

	return (str);
}
