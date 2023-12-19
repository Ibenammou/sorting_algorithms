#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *next, *temp, *temp_next, *temp_prev;
	int x = 0;

	if (list == NULL || (*list)->next == NULL)
		return;
	sorted = *list;
	sorted = sorted->next;
	while (sorted != NULL)
	{
		temp = sorted;
		next = sorted->next;
		temp_next = temp->next;
		temp_prev = temp->prev;

		while (temp->prev != NULL && temp_prev->n > temp->n)
		{
			if (temp_next != NULL)
				temp_next->prev = temp_prev;
			temp_prev->next = temp_next;
			if (temp_prev->prev == NULL)
			{
				temp_prev->prev = temp;
				*list = temp;
				temp->prev = NULL;
			}
			else
			{
				temp->prev = temp_prev->prev;
				temp_prev->prev->next = temp;
				temp_prev->prev = temp;
			}
			temp->next = temp_prev;
			temp_prev = temp->prev;
			temp_next = temp->next;
			print_list(*list);
		}
		sorted = next;
		x++;
	}
}
