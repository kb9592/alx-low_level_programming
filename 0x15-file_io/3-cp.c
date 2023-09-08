#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buff(char *file);
void close_file(int cpfile);

/**
 * create_buff - to assign 1024 bytes to a buffer
 * @file: the name of the buffer that stores the chars
 * Return: points to the new assigned buffer
 */

char *create_buff(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buff);
}

/**
 * close_file - this will close the file descriptors
 * @cpfile: file descriptor that has to be closed
 */

void close_file(int cpfile)
{
	int k;

	k = close(cpfile);

	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close cpfile %d\n", cpfile);
		exit(100);
	}
}

/**
 * main - duplicates from the main file
 * @argc: the number of arguments for the program
 * @argv: pointer to the array of arguments
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	int nfile1, nfile2, rd, j;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buff(argv[2]);
	nfile1 = open(argv[1], O_RDONLY);
	rd = read(nfile1, buff, 1024);
	nfile2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (nfile1 == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		j = write(nfile2, buff, rd);
		if (nfile2 == -1 || j == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		rd = read(nfile1, buff, 1024);
		nfile2 = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buff);
	close_file(nfile1);
	close_file(nfile2);

	return (0);
}
