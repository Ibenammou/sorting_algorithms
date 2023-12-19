#include "sort.h"

/**
 * bit_comp - sorting a sub-array with respect to the
 * Bitonic sort algorithm
 * @dir: direction of sorting
 * @array: array to sort
 * @size: size of array
 * Return: nothing
 */
void bit_comp(char dir, int *array, size_t size)
{
	size_t x, distance;
	int swapping;

	distance = size / 2;
	for (x = 0; x < distance; x++)
	{
		if ((array[x] > array[x + distance]) == dir)
		{
			swapping = array[x];
			array[x] = array[x + distance];
			array[x + distance] = swapping;
		}
	}
}

/**
 * bit_merge - recursively merge two arrays
 * @dir: direction of sorting
 * @array: array to sort
 * @size: size of array
 * Return: nothing
 */
void bit_merge(char dir, int *array, size_t size)
{
	if (size < 2)
		return;
	bit_comp(dir, array, size);
	bit_merge(dir, array, size / 2);
	bit_merge(dir, array + (size / 2), size / 2);
}

/**
 * bit_sorting - Bitonic sorting recursive function
 * @dir: direction of sorting
 * @array: array to sort
 * @size: size of the array
 * @q: total size of the first array
 * Return: nothing
 */
void bit_sorting(char dir, int *array, size_t size, size_t q)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, q, (dir == 1) ? "UP" :
			"DOWN");
	print_array(array, size);
	bit_sorting(1, array, size / 2, q);
	bit_sorting(0, array + (size / 2), size / 2, q);
	bit_merge(dir, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, q, (dir == 1) ? "UP" :
			"DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sorting(1, array, size, size);
}
