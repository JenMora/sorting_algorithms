#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * Shell sort algorithm
 * @array: pointer to array to be sorted
 * @size: the size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, b;
	int tmp;

	gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			b = i;

			while (b >= gap && array[b - gap] > tmp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}
			array[b] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;

	}
}
