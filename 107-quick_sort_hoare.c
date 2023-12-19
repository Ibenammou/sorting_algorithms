#include "sort.h"

/**
 * hoare_part - finds the partition for the quicksort using
 * the Hoare scheme
 * @array: the array
 * @size: size of the array
 * @low: start index for partition
 * @high: end index for partition
 * Return: Index of the pivot element
 */
size_t hoare_part(int *array, ssize_t low, ssize_t high, size_t size)
{
	int swapping, pivot;

	pivot = array[high];
	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				swapping = array[low];
				array[low] = array[high];
				array[high] = swapping;
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}

/**
 * hoare_quic_sort - sorts a partition of an array of integers
 * @array: array to sort
 * @low: start index for partition
 * @high: end index for partition
 * @size: size of array
 * Return: void
 */
void hoare_quic_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = hoare_part(array, low, high, size);
		hoare_quic_sort(array, low, pivot, size);
		hoare_quic_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to sort
 * @size: the size the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_quic_sort(array, 0, size - 1, size);
}
