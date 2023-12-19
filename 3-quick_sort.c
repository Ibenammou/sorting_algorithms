#include "sort.h"

/**
 * swap_heap - swap integers in an array
 * @arr: first int to swap
 * @siz: second int to swap
 */
void swap_heap(int *arr, int *siz)
{
	int temp;

	temp = *arr;
	*arr = *siz;
	*siz = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition
 * scheme
 * @array: the array to be partitioned
 * @low: the lower bound of the partition
 * @high: the upper bound of the partition
 * @size: number of elements in the array
 * Return: the pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int *pivot, x, y;

	pivot = array + high;
	for (y = x = low; x < high; x++)
	{
		if (array[x] < *pivot)
		{
			if (y < x)
			{
				swap_heap(array + x, array + y);
				print_array(array, size);
			}
			y++;
		}
	}
	if (array[y] > *pivot)
	{
		swap_heap(array + y, pivot);
		print_array(array, size);
	}
	return (y);
}

/**
 * quick_sort_recursive - Recursively sorts an array using the Lomuto
 * partition scheme
 * @array: the array to be sorted
 * @low: the lower bound of the partition
 * @high: the upper bound of the partition
 * @size: number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high - low > 0)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick
 * Sort
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
