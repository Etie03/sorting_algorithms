#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, g = 1;
	int *count = NULL, *arr_tmp = NULL;

	if (!array || size < 2)
		return;
	max = array[0];
	while (g < (int) size)
	{
		if (array[g] > max)
			max = array[g];
		g++;
	}
	arr_tmp = malloc(sizeof(int) * size);
	if (!arr_tmp)
		return;
	count = malloc(sizeof(int) * max + 1);
	if (!count)
	{
		free(arr_tmp);
		return;
	}

	for (g = 0; g <= max; ++g)
		count[g] = 0;
	for (g = 0; g < (int) size; ++g)
		count[array[i]]++;
	for (g = 1; g <= max; ++g)
		count[g] = count[g - 1] + count[g];
	print_array(count, max + 1);
	for (g = 0; g < (int) size; ++g)
	{
		arr_tmp[count[array[i]] - 1] = array[i];
		count[array[g]]--;
	}
	for (g = 0; g < (int) size; ++g)
		array[g] = arr_tmp[g];

	free(count);
	free(arr_tmp);
	count = arr_tmp = NULL;
}
