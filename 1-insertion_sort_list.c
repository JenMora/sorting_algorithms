#include "sort.h"

/**
 * insertion_sort_list - function that sorts intergers in d_linked list
 * in ascending order
 * using Insertion sort alogarithm
 * @list: **poointer to list head
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *my_list;
	listint_t *_main;
	listint_t *prev;

	my_list = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (my_list != NULL)
	{
		_main = my_list;
		prev = my_list->prev;

		while (prev != NULL && _main->n < prev->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = _main;
			else
				*list = _main;

			if (_main->next != NULL)
				_main->next->prev = prev;

			prev->next = _main->next;
			_main->prev = prev->prev;
			_main->next = prev;
			prev->prev = _main;

			print_list(*list);

			prev = _main->prev
		}
		my_list = my_list->next
	}
}
