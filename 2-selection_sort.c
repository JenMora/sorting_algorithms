#include "sort.h"

/**
 * selection_sort - this function sorts an array of ints in scending order
 * using the Selectrion Sort alogarith
 * @array: the array to be sorted
 * @size: the size of index
 */

void selection_sort(int *array, size_t size)
{
	size_t a;
	size_t b;
	size_t c;
	int tmp;

	for (a = 0; a < size - 1; a++)
	{
		c = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[c])
				c = b;
		}

		if (c != a)
		{
			tmp = array[a];
			array[a] = array[c];
			array[c] = tmp;
			print_array(array, size);
		}
	}
}
