#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using Shell Sort
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t x, y;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			y = x;

			while (y >= gap && array[y - gap] > temp)
			{
				array[y] = array[y - gap];
				y -= gap;
			}
			array[y] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
