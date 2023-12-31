#include <stdio.h>
#include "sort.h"

/**
* bubble_sort - Sorts an array of integers
* in ascending order using Bubble sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
int swapped;
size_t i = 0;
size_t j = 0;

if  (size <= 1)
{
return;
}

for (i = 0; i < size - 1; i++)
{
swapped = 0;

for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
int temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
swapped = 1;

print_array(array, size);
}
}

if (!swapped)
break;
}
}
