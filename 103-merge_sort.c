#include <stdio.h>
#include <stdlib.h>

/**
* merge - Merge two sub-arrays of array[]
* @array: The original array
* @left: Index of the left sub-array
* @middle: Index of the middle element
* @right: Index of the right sub-array
*/
void merge(int *array, int left, int middle, int right)
{
int i, j, k;
int n1 = middle - left + 1;
int n2 = right - middle;

int *leftArray = malloc(n1 * sizeof(int));
int *rightArray = malloc(n2 * sizeof(int));

for (i = 0; i < n1; i++)
leftArray[i] = array[left + i];
for (j = 0; j < n2; j++)
rightArray[j] = array[middle + 1 + j];

i = 0;
j = 0;
k = left;
while (i < n1 && j < n2)
{
if (leftArray[i] <= rightArray[j])
array[k++] = leftArray[i++];
else
array[k++] = rightArray[j++];
}

while (i < n1)
array[k++] = leftArray[i++];
while (j < n2)
array[k++] = rightArray[j++];

free(leftArray);
free(rightArray);
}

/**
* merge_sort_helper - Recursive function to perform merge sort
* @array: The array to be sorted
* @left: Index of the left sub-array
* @right: Index of the right sub-array
*/
void merge_sort_helper(int *array, int left, int right)
{
if (left < right)
{
int middle = left + (right - left) / 2;
merge_sort_helper(array, left, middle);
merge_sort_helper(array, middle + 1, right);
merge(array, left, middle, right);
}
}

/**
* merge_sort - Sorts an array of integers using merge sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void merge_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
return;
merge_sort_helper(array, 0, size - 1);
}

/**
* print_array - Prints an array of integers
* @array: The array to be printed
* @size: Number of elements in the array

*void print_array(int *array, size_t size)
*{
*size_t i;

*for (i = 0; i < size; i++)
*{
*printf("%d", array[i]);
*if (i < size - 1)
*printf(", ");
*}
*printf("\n");
*}
*/

