#include "lists.h"

/**
 * listint_len -  a function that returns the number of elements
 * in a linked listint_t list
 * @h: pointer to the beginning node
 * Return: number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t k = 0;

	while (h)
	{
		k++;
		h = h->next;
	}
	return (k);
}
