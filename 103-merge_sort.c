include "sort.h"
/**
 * merger_sort - initiate merge sort
 * @array: array
 * @temp: temporary array
 * @size: size of the array
 */
void merger_sort(int *array, int *temp, size_t size)
{
	size_t half = size / 2, m = 0, p = 0, k;

	if (size < 2)
		return;

	merger_sort(array, temp, half);
	merger_sort(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (k = 0; k < size; k++)
		if (p >= size - half || (m < half && array[m] < (array + half)[p]))
		{
			temp[k] = array[m];
			m++;
		}
		else
		{
			temp[k] = (array + half)[p];
			p++;
		}
	for (k = 0; k < size; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts by merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	_merge_sort(array, temp, size);
	free(temp);
}
