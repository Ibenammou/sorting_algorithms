#include "sort.h"

/**
 * swap_heap - swap array
 * @arr: pointer to the first int
 * @siz: pointer to the second int
 */
void swap_heap(int *arr, int *siz)
{
	int temp;

	temp = *arr;
	*arr = *siz;
	*siz = temp;
}

/**
 * heapify - Heapify a heap node
 * @array: array
 * @n: base row of the tree
 * @x: root index
 * @size: array size
 */
void heapify(int *array, size_t size, size_t n, size_t x)
{
	size_t largest, left, right;

	left = 2 * x + 1;
	right = 2 * x + 2;
	largest = x;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != x)
	{
		swap_heap(array + x, array + largest);
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

/**
 * heap_sort - sorts an array of integers using heap sort
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int w;

	if (array == NULL || size < 2)
		return;

	for (w = (size / 2) - 1; w >= 0; w--)
		heapify(array, size, size, w);

	for (w = size - 1; w > 0; w--)
	{
		swap_heap(array, array + w);
		print_array(array, size);
		heapify(array, size, w, 0);
	}
}
