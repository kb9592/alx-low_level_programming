#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * copen_file - checks for files
 * @file_from: file to transfer from
 * @file_to: destination file
 * @argv: pointer for argument
 * Return: 0
 */
void copen_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - makes checks from files
 * @argc: the number of arguments for the program
 * @argv: points to arguments vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	int anthr;
	ssize_t kl, ti;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	copen_file(file_from, file_to, argv);

	kl = 1024;
	while (kl == 1024)
	{
		kl = read(file_from, buffer, 1024);
		if (kl == -1)
			copen_file(-1, 0, argv);
		ti = write(file_to, buffer, kl);
		if (ti == -1)
			copen_file(0, -1, argv);
	}

	anthr = close(file_from);
	if (anthr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	anthr = close(file_to);
	if (anthr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
