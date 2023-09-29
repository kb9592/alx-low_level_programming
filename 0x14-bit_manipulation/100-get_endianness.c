#include "main.h"

/**
 * get_endianness - this function checks for endisnness
 * Return: 0 if it is big endian, or 1 if it is the little endian
 */

int get_endianness(void)
{
	unsigned int kz = 1;
	char *ab = (char *) &kz;

	return (*ab);
}
