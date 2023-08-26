#include "lists.h"

/**
 * list_len - a function that returns the number
 * of elements in a linked list_t list
 * @h: the pointer to the first node
 * Return: the number of elements in the list
 */

size_t list_len(const list_t *h)
{
	int k;

	if (h == NULL)
		return (0);

	for (k = 1; h->next != NULL; k++)
		h = h->next;
	return (k);
}
