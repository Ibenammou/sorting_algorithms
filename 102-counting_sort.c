#include "sort.h"

/**
 * counting_sort - function to sorts an array of integers in ascending order
 * using the counting sort algorithm
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int x, max;
	int *counting = NULL, *sorted = NULL;
	size_t y, temp, sort_ind = 0;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	for (y = 0, max = 0; y < size; y++)
	{
		sorted[y] = array[y];
		if (array[y] > max)
			max = array[y];
	}
	counting = malloc(sizeof(int) * (max + 1));
	if (counting == NULL)
	{
		free(sorted);
		return;
	}
	for (x = 0; x <= max; x++)
		counting[x] = 0;
	for (y = 0; y < size; y++)
		counting[array[y]] += 1;
	for (x = 0; x <= max; x++)
	{
		temp = counting[x];
		counting[x] = sort_ind;
		sort_ind += temp;
	}
	for (y = 0; y < size; y++)
	{
		array[counting[sorted[y]]] = sorted[y];
		counting[sorted[y]] += 1;
	}
	print_array(counting, max + 1);
	free(counting);
	free(sorted);
}
