#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file
 * and prints it to the POSIX standard output
 * @filename: the text file to be read
 * @letters: the number of letters or bytes that will be read
 * Return: the original number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *buffer;
	ssize_t rdfile, wrtfile;

	if (!filename)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	rdfile = read(file, buffer, letters);
	wrtfile = write(STDOUT_FILENO, buffer, rdfile);

	close(file);
	free(buffer);
	return (wrtfile);
}
