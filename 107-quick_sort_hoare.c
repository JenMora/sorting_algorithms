#include <stdio.h>
#include "sort.h"

/**
* swap - Swaps two integers using pointers
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* hoare_partition - Partitions the array using Hoare partition scheme
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* Return: Index of the partition
*/
int hoare_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return j;

swap(&array[i], &array[j]);
}
}

/**
* quick_sort_recursive - Recursively sorts the array using Quick sort
* @array: Array to be sorted
* @low: Starting index of the range to be sorted
* @high: Ending index of the range to be sorted
*/
void quick_sort_recursive(int *array, int low, int high)
{
if (low < high)
{
int partition_index = hoare_partition(array, low, high);
quick_sort_recursive(array, low, partition_index);
quick_sort_recursive(array, partition_index + 1, high);
}
}

/**
* quick_sort_hoare - Sorts an array using Quick sort (Hoare partition scheme)
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
print_array(array, size);
quick_sort_recursive(array, 0, size - 1);
}
