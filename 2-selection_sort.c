#include "sort.h"
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array
 * @size: array size
 *
 * Return: void
 **/
void selection_sort(int *array, size_t size)
{
	size_t m, p, g;
	int temp;

	if (!array || !size)
		return;
	for (m = 0; m < size - 1; m++)
	{
		for (p = size - 1, g = m + 1; p > m; p--)
		{
			if (array[p] < array[g])
			{
				g = p;
			}
		}
		if (array[m] > array[g])
		{
			temp = array[m];
			array[m] = array[g];
			array[g] = temp;
			print_array(array, size);
		}
	}
}
