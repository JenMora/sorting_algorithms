#include "sort.h"

/**
* sift_down - Rearranges the heap to maintain the max heap property
* @arr: Array to sort
* @s_idx: Starting index
* @e_idx: Ending index
* @size: Size of the array
*
* Description: This function rearranges the heap in a way that satisfies
* the max heap property, where each parent node is greater than or equal to
* its child nodes.
*/
void sift_down(int *arr, int s_idx, int e_idx, int size);

/**
* create_heap - Creates a max heap from the given array
* @arr: Array to sort
* @s: Size of the array
*
* Description: This function takes an array and constructs a max heap from it.
* It starts from the last non-leaf node and calls sift_down on each node to
* ensure the max heap property is satisfied.
*/
void create_heap(int *arr, size_t s);

/**
* heap_sort - Heap sort starting point
* @arr: Array to sort
* @s: Size of the array
*
* Description: This function performs heap sort on the given array.
* It first creates a max heap and then repeatedly extracts the maximum
* element from the heap and places it at the end of the array, adjusting
* the heap after each extraction.
*/
void heap_sort(int *arr, size_t s);

void sift_down(int *arr, int s_idx, int e_idx, int size)
{
int left_child, temp_idx, swap, temp;

temp_idx = s_idx + 1;
left_child = temp_idx * 2;

while (left_child - 1 <= e_idx)
{
swap = left_child - 1;

if (left_child <= e_idx) /* Right child actual index */
{
if (arr[left_child] > arr[swap])
swap = left_child;
}

if (arr[s_idx] >= arr[swap])
return;

temp = arr[swap];
arr[swap] = arr[s_idx];
arr[s_idx] = temp;

s_idx = swap;
temp_idx = s_idx + 1;
left_child = temp_idx * 2;

print_array(arr, size);
}
}

void create_heap(int *arr, size_t s)
{
int s_idx = s - 1;
int n = s;

while (s_idx >= 0)
{
sift_down(arr, s_idx, s - 1, n);
s_idx--;
}
}

void heap_sort(int *arr, size_t s)
{
int temp, n;

if (s <= 1)
return;

/* Create the heap */
create_heap(arr, s);

/* Order the list using sift down */
n = s;

while (s > 0)
{
if (s - 1 != 0)
{
temp = arr[0];
arr[0] = arr[s - 1];
arr[s - 1] = temp;

print_array(arr, n);
sift_down(arr, 0, s - 2, n);
}

s--;
}
}

