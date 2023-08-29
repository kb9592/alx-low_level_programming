#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list
 * @head: pointer to the first node of the list to be freed
 * Description: the function sets the head to NULL
 */

void free_listint2(listint_t **head)
{
	listint_t *freelist;

	if (!head)
		return;

	while (*head)
	{
		freelist = (*head)->next;
		free(*head);
		*head = freelist;
	}
	*head = NULL;
}
