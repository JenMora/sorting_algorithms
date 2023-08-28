#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of array to look out for
 * so as to arrange in ascending order
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	recursive_sorting(array, 0, size - 1, size);
}

/**
 * recursive_sorting - thr recursive function that will perform
 * the sorting action
 * @array: the array to be sorted
 * @least: the first idx
 * @most: last index
 * @size: size of array
 */
void recursive_sorting(int *array, int least, int most, size_t size)
{
	int mid_point;

	if (least < most)
	{
		mid_point = lomuto_with_partition(array, least, most, size);
		recursive_sorting(array, least, mid_point - 1, size);
		recursive_sorting(array, mid_point + 1, most, size);
	}
}

/**
 * lomuto_with_partition - the scheme to quicksort from lomuto
 * @array: the pointer to array to be sorted
 * @least: the starting point
 * @most: the end point
 * @size: the size of array
 * Return: position of the mid_point
 */
int lomuto_with_partition(int *array, int least, int most, size_t size)
{
	int mid_point;
	int a, b, tmp;

	mid_point = array[most];
	a = least - 1;

	for (b = least; b <= most - 1; b++)
	{
		if (array[b] <= mid_point)
		{
			a++;
			if (a != b)
			{
				tmp = array[a];
				array[a] = array[b];
				array[b] = tmp;
				print_array(array, size);
			}
		}
	}
	if (a + 1 != most)
	{
		tmp = array[a + 1];
		array[a + 1] = array[most];
		array[most] = tmp;
		print_array(array, size);
	}
	return (a + 1);
}
