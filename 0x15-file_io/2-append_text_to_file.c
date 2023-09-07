#include "main.h"
#include <string.h>

/**
 * append_text_to_file - a function that appends
 * text at the end of a file
 * @filename: the name of the file
 * @text_content: is the NULL terminated string to
 * add at the end of the file
 * Return: 1 on success and -1 if it fails
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int apfile, wrtfl, length = 0;

	if (filename == NULL)
		return (-1);

	apfile = open(filename, O_WRONLY | O_APPEND);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	wrtfl = write(apfile, text_content, length);

	if (apfile == -1 || wrtfl == -1)
		return (-1);

	close(apfile);

	return (1);
}
