#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - a function that prints all the elements of a list_t list.
 * @h: the pointer to the list_t list
 * Return: the total number of nodes in the linked list
 */

size_t print_list(const list_t *h)
{
	int k;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		k++;
		h = h->next;
	}

	return (k);
}
