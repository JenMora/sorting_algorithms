#ifndef SORT_H


#define SORT_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

#endif
