#include "sort.h"

/**
 * lom_partition - scans a partition of an array of integers
 * @array: array
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: integer
 */
int lom_partition(int *array, int low, int high, size_t size)
{
	int m, k, pivot, temp;

	pivot = array[high];
	m = low;
	for (k = low; k < high; k++)
	{
		if (array[k] < pivot)
		{
			temp = array[m];
			array[m] = array[k];
			array[k] = temp;
			if (array[m] != array[k])
				print_array(array, size);
			m++;
		}
	}
	temp = array[m];
	array[m] = array[high];
	array[high] = temp;
	if (array[m] != array[high])
		print_array(array, size);
	return (m);
}

/**
 * lomuto_quicksort - recursively sorts array of integers
 * @array: array
 * @low: low index
 * @high: high index
 * @size: the size of array
 */
void lomuto_quicksort(int *array, int low, int high, size_t size)
{
	int m;

	if (low < high)
	{
		m = partition(array, low, high, size);
		lomuto_quicksort(array, low, m - 1, size);
		lomuto_quicksort(array, m + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array using quick_sort algorithm
 * @array: array
 * @size: the size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_quicksort(array, 0, (int)size - 1, size);
}
