#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * add_node_end - a function that adds a new
 * node at the end of a list_t list
 * @head: the head of a list_t list
 * @str: the string for storing in the list
 * Return: the address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *old;
	int k;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	for (k = 0; str[k]; k++)

	new_node->len = k;
	new_node->next = NULL;
	old = *head;

	if (old == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (old->next != NULL)
			old = old->next;
		old->next = new_node;
	}

	return (*head);
}
