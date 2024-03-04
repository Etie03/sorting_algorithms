#include "sort.h"

/**
  * bubble_sort - Sorts an array of integers in ascending
  * order using the Bubble sort algorithm.
  * @array: The array of integers to sort
  * @size: The size of the array of integers
  *
  * Return: Nothing!
  */

void bubble_sort(int *array, size_t size)
{
	size_t m = 0, p = 0;
	int tmp = 0;

	for (m = 0; m < size; m++)
		for (p = 0; p < size - 1; p++)
			if (array[p] > array[p + 1])
			{
				tmp = array[p];
				array[p] = array[p + 1];
				array[p + 1] = tmp;
				print_array(array, size);
			}
}
