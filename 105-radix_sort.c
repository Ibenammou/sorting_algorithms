#include "sort.h"

/**
 * find_max - find the max element in the array
 * @array: the array
 * @size: size of the array
 * Return: Max element
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t x;

	for (x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	return (max);
}

/**
 * count_sort - perform counting sort on the specified digit
 * @array: the array
 * @size: size of the array
 * @digit: digit
 */
void count_sort(int *array, size_t size, int digit)
{
	int *output, x;
	int count[10] = {0};
	size_t y;

	output = malloc(size * sizeof(int));

	for (y = 0; y < size; y++)
		count[(array[y] / digit) % 10]++;
	for (x = 1; x < 10; x++)
		count[x] += count[x - 1];
	for (x = size - 1; x >= 0; x--)
	{
		output[count[(array[x] / digit) % 10] - 1] = array[x];
		count[(array[x] / digit) % 10]--;
	}
	for (y = 0; y < size; y++)
		array[y] = output[y];
	free(output);
}

/**
 * radix_sort - main radix sort function
 * @array: the array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, digit;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);

	for (digit = 1; max / digit > 0; digit *= 10)
	{
		count_sort(array, size, digit);
		print_array(array, size);
	}
}
