#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a
 * new node at a given position
 * @head: the first node of the ppointer
 * @idx: the index of the list where the
 * new node should be added. Index starts at 0
 * @n: value of new node
 * Return: the address of the new node, or NULL if it fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *insert_new;
	listint_t *n_node = *head;
	unsigned int k;

	if (idx != 0)
	{
		insert_new = *head;

		for (k = 0; k < idx - 1 && insert_new != NULL; k++)
		{
			insert_new = insert_new->next;
		}
		if (insert_new == NULL)
			return (NULL);
	}

	n_node = malloc(sizeof(listint_t));

	if (n_node == NULL)
		return (NULL);

	n_node->n = n;
	if (idx == 0)
	{
		n_node->next = *head;
		*head = n_node;
		return (n_node);
	}
	n_node->next = insert_new->next;
	insert_new->next = n_node;
	return (n_node);
}
