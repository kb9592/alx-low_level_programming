#include "lists.h"

/**
 * free_listint_safe - a function that frees a listint_t list
 * @h: this points to the first node in the list
 * Description: function sets the head to NULL
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t range = 0;
	int change;
	listint_t *i;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		change = *h - (*h)->next;
		if (change > 0)
		{
			i = (*h)->next;
			free(*h);
			*h = i;
			range++;
		}
		else
		{
			free(*h);
			*h = NULL;
			range++;
			break;
		}
	}

	*h = NULL;

	return (range);
}
