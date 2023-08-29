#include "sort.h"

/**
 * cocktail_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: ythe list to be soted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *my_list, *tmp;
	int sort_res;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		sort_res = 0;
		for (my_list = *list; my_list->next != NULL; my_list = my_list->next)
		{
			if (my_list->n > my_list->next->n)
			{
				tmp = my_list->next;
				if (my_list->prev != NULL)
					my_list->prev->next = tmp;
				else
					*list = tmp;
				if (tmp->next != NULL)
					tmp->next->prev = my_list;
				my_list->next = tmp->next;
				tmp->prev = my_list->prev;
				my_list->prev = tmp;
				tmp->next = my_list;

				print_list(*list);
				sort_res = 1;
			}
		}
		if (sort_res == 0)
			break;
		sort_res = 0;
		for (my_list = my_list->prev; my_list->prev != NULL;
				my_list = my_list->prev)
		{
			if (my_list->n < my_list->prev->n)
			{
				tmp = my_list->prev;
				if (my_list->next != NULL)
					my_list->next->prev = tmp;
				tmp->next = my_list->next;
				if (tmp->prev != NULL)
					tmp->prev->next = my_list;
				else
					*list = my_list;
				my_list->next = tmp;
				my_list->prev = tmp->prev;
				tmp->prev = my_list;
				print_list(*list);
				sort_res = 1;
			}
		}
	} while (sort_res);
}
