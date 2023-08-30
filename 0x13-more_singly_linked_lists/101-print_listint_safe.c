#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * r - reallocates memory for an array of pointers
 * @size: the size of the new list
 * @new: new node to be added to the list
 * @list: old list to correct
 * Return: pointer to new list
 */

const listint_t **r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **new_list;
	size_t k;

	new_list = malloc(size * sizeof(listint_t *));
	if (new_list == NULL)
	{
		free(list);
		exit(98);
	}

	for (k = 0; k < size - 1; k++)
		new_list[k] = list[k];
	new_list[k] = new;
	free(list);
	return (new_list);
}
/**
 * print_listint_safe - a function that prints a listint_t linked list
 * @head: pointer to the beginning of the list
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t k, dig = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (k = 0; k < dig; k++)
		{
			if (head == list[k])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (dig);
			}
		}
		dig++;
		list = r(list, dig, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (dig);
}
