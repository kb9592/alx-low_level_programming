#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: the string to be evaluated
 * Return: 0 if a non-digit is found, 1 if not
 */
int is_digit(char *s)
{
	int k = 0;

	while (s[k])
	{
		if (s[k] < '0' || s[k] > '9')
			return (0);
		k++;
	}
	return (1);
}

/**
 * _strlen - return the length of a string
 * @s: the string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int k = 0;

	while (s[k] != '\0')
	{
		k++;
	}
	return (k);
}

/**
 * errors - controls errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies 2 positive numbers
 * @argc: the number of arguments
 * @argv: the array of the arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len3, k, carry, num1, num2, *output, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		errors();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len3 = len1 + len2 + 1;
	output = malloc(sizeof(int) * len3);
	if (!output)
		return (1);
	for (k = 0; k <= len1 + len2; k++)
		result[k] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		num1 = s1[len1] - '0';
		carry = 0;
	}

	for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
	{
		num2 = s2[len2] - '0';
		carry += output[len1 + len2 + 1] + (num1 * num2);
		output[len1 + len2 + 1] = carry % 10;
		carry /= 10;
	}
	if (carry > 0)
	{
		output[len1 + len2 + 1] += carry;
	}
	for (k = 0; k < len3 - 1; k++)
	{
		if (result[k])
			a = 1;
		if (a)
			_putchar(output[k] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(output);

	return (0);
}
