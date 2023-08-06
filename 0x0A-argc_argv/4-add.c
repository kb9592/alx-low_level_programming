#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - check if the strings are digits
 * @str: array str
 * Return: 0 (Success)
 */
int check_num(char *str)
{
	/*Declaring variables*/
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /*count string*/

	{
		if (!isdigit(str[count])) /*to check if the str are digits*/
		{
			return (0);
		}

		count++;
	}
	return (1);
}
/**
 * main - prints the name of the program
 * @argc: counts the arguments
 * @argv: the arguments
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	/*Declaring variables*/
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))
		{
			str_to_int = atoi(argv[count]);
			sum += str_to_int;
		}

		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", sum);

	return (0);
}
