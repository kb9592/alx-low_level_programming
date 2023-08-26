#include "lists.h"
#include "lists.h"

/**
 * free_list - a function that frees a list_t list
 * @head: the head of list_t list
 */

void free_list(list_t *head)
{
	list_t *node;

	if (head == NULL)
		return;
	while ((node = head) != NULL)
	{
		head = head->next;
		free(node->str);
		free(node);
	}
}
