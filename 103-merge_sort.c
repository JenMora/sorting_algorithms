#include "sort.h"

/**
* customMerge - this function merges an array
* @arr: array to sort
* @copy: copy array
* @start: start index
* @end: end index + 1
* @middle: middle index
* Return: nothing
*/
void customMerge(int *arr, int *copy, int start, int end, int middle)
{
int i = start, j = middle, k, flag;

printf("Merging...\n");
printf("[left]: ");
flag = 0;
for (i = start; i < middle; i++)
{
if (flag)
printf(", ");
printf("%d", arr[i]);
flag = 1;
}
printf("\n[right]: ");
flag = 0;
for (i = middle; i < end; i++)
{
if (flag)
printf(", ");
printf("%d", arr[i]);
flag = 1;
}
printf("\n");

i = start;
j = middle;
for (k = start; k < end; k++)
{
if (i < middle && (j >= end || arr[i] <= arr[j]))
{
copy[k] = arr[i];
i++;
}
else
{
copy[k] = arr[j];
j++;
}
}

for (k = start; k < end; k++)
arr[k] = copy[k];
}

/**
* customMergeSort - This function merges an array and is a starting point
* @arr: array to sort
* @copy: copy array
* @start: start index
* @end: end index + 1
* Return: nothing
*/
void customMergeSort(int *arr, int *copy, int start, int end)
{
int middle, k;

if (end - start <= 1)
return;

middle = (start + end) / 2;
customMergeSort(arr, copy, start, middle);
customMergeSort(arr, copy, middle, end);
customMerge(arr, copy, start, end, middle);

printf("[Done]: ");
for (k = start; k < end; k++)
{
if (k != start)
printf(", ");
printf("%d", arr[k]);
}
printf("\n");
}

/**
* merge_sort - A function that  merge sort starting point
* @array: array to sort
* @size: length of the array
* Return: nothing
*/
void merge_sort(int *array, size_t size)
{
size_t k;
int *copy_arr = malloc(sizeof(int) * size);

/* Create a copy array */
for (k = 0; k < size; k++)
copy_arr[k] = array[k];

/* Sort */
customMergeSort(array, copy_arr, 0, size);

free(copy_arr);
}
