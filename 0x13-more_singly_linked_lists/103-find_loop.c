#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list
 * @head: the pointer of the first node
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *one, *two;

	if (!head)
		return (NULL);

	while (one && two && two->next)
	{
		one = one->next;
		two = two->next->next;
		if (one == two)
		{
			one = head;
			while (one != two)
			{
				one = one->next;
				two = two->next;
			}
			return (two);
		}
	}
	return (NULL);
}
