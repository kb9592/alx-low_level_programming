#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: a pointer that points to the name of the file to create
 * @text_content: points to the string to write to the file
 * Return: 1 on success, or -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int newfile, units, range = 0;

	if (filename == NULL)
		return (-1);

	newfile = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (newfile == -1)
		return (-1);

	units = write(newfile, text_content, range);

	if (text_content != NULL)
	{
		for (range = 0; text_content[range];)
			range++;
	}

	if (newfile == -1 || units == -1)
		return (-1);

	close(newfile);
	return (1);
}
