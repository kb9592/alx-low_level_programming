#include "lists.h"

/**
 * pop_listint - a function that deletes the head node of a
 * listint_t linked list, and returns the head node’s data (n)
 * @head: the pointer of the first node
 * Return: 0 if linked list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *del_list;
	int n;

	if (!head || !*head)
		return (0);

	del_list = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = del_list;
	return (n);
}
