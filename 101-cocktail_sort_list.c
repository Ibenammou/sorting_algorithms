#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: pointer tot the doubly linked list
 * @a: node to swap
 */
void swap_nodes(listint_t **list, listint_t *a)
{
	a->next->prev = a->prev;
	if (a->prev)
		a->prev->next = a->next;
	else
		*list = a->next;
	a->prev = a->next;
	a->next = a->next->next;
	a->prev->next = a;
	if (a->next)
		a->next->prev = a;
}

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 * using the cocktail shaker sort algorithm
 * @list: a pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap_nodes(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_nodes(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
