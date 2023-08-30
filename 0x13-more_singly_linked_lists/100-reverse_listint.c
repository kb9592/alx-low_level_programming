#include "lists.h"

/**
 * reverse_listint - a function that reverses
 * a listint_t linked list
 * @head: location of pointer of first node
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *rvse = NULL;
	listint_t *frwd = NULL;

	if (!head || !*head)
		return (NULL);

	rvse = *head;
	*head = NULL;
	while (rvse)
	{
		frwd = rvse->next;
		rvse->next = *head;
		*head = rvse;
		rvse = frwd;
	}
	return (*head);
}

