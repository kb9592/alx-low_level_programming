#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the
 * nth node of a listint_t linked list
 * @head: pointer to first node in list
 * @index: the index of the node, starting at 0
 * Return: pointer of index, or if the node does not exist, return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int k;

	if (head == NULL)
		return (NULL);

	for (k = 0; k < index; k++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}

	return (head);
}
