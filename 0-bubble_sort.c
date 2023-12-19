#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		swapped = 0;
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
