#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid -  a function that returns a pointer to
 * a 2 dimensional array of integers
 * @width: width of the array
 * @height: the height of the array
 * Return: a pointer to the 2 dimensional array of integers
 */
int **alloc_grid(int width, int height)
{
	int **array, n, m;
	int len = width * height;

	if (len <= 0)
		return (NULL);

	array = (int **)malloc(sizeof(int *) * height);
	if (array == NULL)
		return (NULL);

	for (n = 0; n < height; n++)
	{
		array[n] = (int *)malloc(sizeof(int) * width);
		if (array[n] == NULL)
		{
			for (n--; n >= 0; n--)
				free(array[n]);
			free(array);
			return (NULL);
		}
	}

	for (n = 0; n < height; n++)
		for (m = 0; m < width; m++)
			array[n][m] = 0;

	return (array);
}
