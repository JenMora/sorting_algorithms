#include "sort.h"

void quick_sort_r(int *arr, int the_start, int the_end, size_t size);
int hoares_partition(int *arr, int the_start, int the_end, size_t size);
void swap(int *integer_a, int *integer_b);

/**
* quick_sort_hoare - Entry point for the Hoare's Quick Sort algorithm.
* @array: Array to be sorted.
* @size: Size of the array.
*
* Return: void
*/
void quick_sort_hoare(int *array, size_t size)
{
int the_start = 0;
int the_end = size - 1;

if (size < 2)
return;

quick_sort_r(array, the_start, the_end, size);
}

/**
* quick_sort_r - Quick sort implementation using the Hoare's partition scheme.
* @arr: Array to be sorted.
* @the_start: Starting index of the partition.
* @the_end: Ending index of the partition.
* @size: Size of the array.
*
* Return: void
*/
void quick_sort_r(int *arr, int the_start, int the_end, size_t size)
{
if (the_start < the_end)
{
int pivot_index = hoares_partition(arr, the_start, the_end, size);

quick_sort_r(arr, the_start, pivot_index, size);

quick_sort_r(arr, pivot_index + 1, the_end, size);
}
}

/**
* hoares_partition - Partitioning function based on Hoare's scheme.
* @arr: Array to be partitioned.
* @the_low: Starting index of the partition.
* @the_high: Ending index of the partition.
* @size: Size of the array.
*
* Return: Index of the partition.
*/
int hoares_partition(int *arr, int the_low, int the_high, size_t size)
{
int pivot = arr[the_high];
int i = the_low - 1;
int j = the_high + 1;

while (1)
{
do {
i++;
} while (arr[i] < pivot);

do {
j--;
} while (arr[j] > pivot);

if (i > j)
{
return (j);
}
if (i < j)
{
swap(&arr[i], &arr[j]);
print_array(arr, size);
}
}
}

/**
* swap - Swaps two integer values.
* @integer_a: Pointer to the first integer.
* @integer_b: Pointer to the second integer.
*
* Return: void
*/
void swap(int *integer_a, int *integer_b)
{
int temp = *integer_a;
*integer_a = *integer_b;
*integer_b = temp;
}

