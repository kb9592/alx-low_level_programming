#include "lists.h"

/**
 * add_nodeint_end - a function that adds a new node
 * at the end of a listint_t list
 * @head: the pointer to the beginning of the list
 * @n: the value to contain the new node
 * Return: the address of the new element, or NULL if it fails
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode;
	listint_t *end;

	newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (!*head)
		*head = newnode;

	while (end->next)
		end = end->next;

	end->next = newnode;
	return (newnode);
}
