#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: pointer to array being sorted
 * @size: size of array to arrage
 */

/*void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count, *new_sort;
	int j;
	size_t high;

	high = array[0];
	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > high)
			high = array[i];
	}
	count = (int *)malloc((high + 1) * sizeof(int));
	if (count == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	for (i = 0; i <= high; i++)
		count[array[i]]++;
	new_sort = (int *)malloc(size * sizeof(int));
	if (new_sort == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(count);
		return;
	}
	j = 0;
	for (i = 0; i <= high; i++)
	{
		while (count[i] > 0)
		{
			new_sort[j++] = i;
			count[i]--;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = new_sort[i];
	}
	print_array(count, high + 1);

	free(count);
	free(new_sort);
}*/
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count, *new_sort;
	int j;
	size_t high;

	high = array[0];
	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > high)
			high = array[i];
	}
	count = (int *)malloc((high + 1) * sizeof(int));
	if (count == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	for (i = 0; i <= high; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	new_sort = (int *)malloc(size * sizeof(int));
	if (new_sort == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(count);
		return;
	}
	j = 0;
	for (i = 0; i <= high; i++)
	{
		while (count[i] > 0)
		{
			new_sort[j++] = i;
			count[i]--;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = new_sort[i];
	}
	print_array(array, size);

	free(count);
	free(new_sort);
}
