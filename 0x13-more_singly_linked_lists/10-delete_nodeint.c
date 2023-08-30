#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the
 * node at index index of a listint_t linked list
 * @head: pointer to first node of list
 * @index: the index of the node that should be deleted and index starts at 0
 * Return: 1 if it succeeds or  -1 if it fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *delnode;
	listint_t *former;

	unsigned int k = 0;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		former = *head;
		*head = (*head)->next;
		free(former);
		return (1);
	}

	delnode = *head;

	while (delnode)
	{
		if (k == index)
		{
			former->next = delnode->next;
			free(delnode);
			return (1);
		}

		k++;

		former = delnode;
		delnode = delnode->next;
	}
	return (-1);
}
