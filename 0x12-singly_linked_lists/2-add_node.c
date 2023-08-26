#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - a function that adds a new node
 * at the beginning of a list_t list
 * @head: points to the head of the list
 * @str: string to be added
 * Return: a pointer to the first node or NULL if fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *nn;
	int range = 0;

	nn = malloc(sizeof(list_t));
	if (nn == NULL)
		return (NULL);

	while (str[range])
		range++;

	nn->next = *head;
	nn->str = strdup(str);
	nn->len = range;
	*head = nn;
	return (nn);
}
