#include "sort.h"

/**
 * merge - Merges two subarrays back into the original array
 * @strt: the original array
 * @midd: the left subarray
 * @end: the right subarray
 * @left: size of the left subarray
 * @right: size of the right subarray
 */
void merge(size_t strt, size_t midd, size_t end, int *right, int *left)
{
	size_t x, y, z;

	printf("Merging...\n");
	printf("[left]: ");
	print_array((left + strt), (midd - strt));
	printf("[right]: ");
	print_array((left + midd), (end - midd));
	x = strt;
	y = midd;
	for (z = strt; z < end; z++)
	{
		if (x < midd && (y >= end || left[x] <= left[y]))
		{
			right[z] = left[x];
			x++;
		}
		else
		{
			right[z] = left[y];
			y++;
		}
	}
	printf("[Done]: ");
	print_array(right + strt, end - strt);
}

/**
 * splt_merge - recursively splits the array and merges the sorted array
 * @strt: starting index (inclusive)
 * @end: end index
 * @array: the array to sort
 * @sorted: copy of the sorted array
 */
void splt_merge(size_t strt, size_t end, int *array, int *sorted)
{
	size_t midd;

	if (end - strt < 2)
		return;
	midd = (strt + end) / 2;
	splt_merge(strt, midd, array, sorted);
	splt_merge(midd, end, array, sorted);
	merge(strt, midd, end, array, sorted);
	for (midd = strt; midd < end; midd++)
		sorted[midd] = array[midd];
}

/**
 * merge_sort - sorts an array of integers using the merge sort
 * algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t x;
	int *sorted;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	for (x = 0; x < size; x++)
		sorted[x] = array[x];
	splt_merge(0, size, array, sorted);
	free(sorted);
}
