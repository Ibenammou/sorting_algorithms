#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y;
	int min, temp;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}

		if ((int)min != (int)x)
		{
			temp = array[x];
			array[x] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
