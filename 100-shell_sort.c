#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size
 * Return: void
 **/
void shell_sort(int *array, size_t size)
{
	int m = 0, p = 0, r = 1, a = 0;

	if (!array || size < 2)
		return;

	while (r < (int) size / 3)
		r = r * 3 + 1;

	while (r > 0)
	{
		p = r;
		while (p < (int) size)
		{
			a = array[p];
			m = p;

			while (m > r - 1 && array[m - r] >= a)
			{
				array[m] = array[m - r];
				m = m - r;
			}

			array[m] = a;
			p++;
		}
		print_array(array, size);
		r = (r - 1) / 3;
	}
}
