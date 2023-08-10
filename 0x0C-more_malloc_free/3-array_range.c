#include <stdlib.h>
#include "main.h"

/**
 * *array_range - a function that creates an array of integers
 * @min: the minimum range of values stored
 * @max: the maximum range of values being stored
 * and the number of elements
 * Return: the pointer to the new array
 */

int *array_range(int min, int max)
{
	int *ptr;
	int n, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ptr = malloc(sizeof(int) * size);

	if (ptr == NULL)
		return (NULL);

	for (n = 0; min <= max; n++)
		ptr[n] = min++;

	return (ptr);
}
