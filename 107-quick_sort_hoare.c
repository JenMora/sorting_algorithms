#include <stdio.h>
#include "sort.h"

void swap(int *i, int *j);
int hoare_partition(int *array, int low, int high, size_t);
void quick_sort_recursive(int *array, int low, int high, size_t size);
/**
* swap - Swaps two integers using pointers
* @i: Pointer to the first integer
* @j: Pointer to the second integer
* Return: Nothing
*/
void swap(int *i, int *j)
{
int temp = *i;
*i = *j;
*j = temp;
}

/**
* hoare_partition - Partitions the array using Hoare partition scheme
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size_t: the array size
* Return: Index of the partition
*/
int hoare_partition(int *array, int low, int high, size_t)
{
int pivot = array[high];
int a = low - 1;
int b = high + 1;
size_t = whole_size;

while (1)
{
do {
a++;
} while (array[a] < pivot);

do {
b--;
} while (array[b] > pivot);

if (a >= b)
return (b);

swap(&array[a], &array[b]);
print_array(array, whole_size);
}
}

/**
* quick_sort_recursive - Recursively sorts the array using Quick sort
* @array: Array to be sorted
* @low: Starting index of the range to be sorted
* @high: Ending index of the range to be sorted
* @size_t: the array size
* Return: Nothing
*/
void quick_sort_recursive(int *array, int low, int high, size_t)
{
size_t = size;

if (low < high)
{
int partition_index = hoare_partition(array, low, high, size);

quick_sort_recursive(array, low, partition_index, size);

quick_sort_recursive(array, partition_index + 1, high, size);
}
}

/**
* quick_sort_hoare - Sorts an array using Quick sort (Hoare partition scheme)
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
int low = 0 :
int high = size - 1;

if  (size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}

