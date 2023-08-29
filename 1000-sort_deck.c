#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"
#include "sort.h"

int compare_cards(const void *a, const void *b);

/**
* compare_cards - This function compares two cards for sorting.
* @a: Pointer to a pointer of the first card node.
* @b: Pointer to a pointer of the second card node.
*
* Return: Negative if a < b, positive if a > b, 0 if equal.
*/
int compare_cards(const void *a, const void *b)
{
const card_t *card_a = (*(const deck_node_t **)a)->card;
const card_t *card_b = (*(const deck_node_t **)b)->card;

int value_cmp = strcmp(card_a->value, card_b->value);
if (value_cmp != 0)
{
return (value_cmp);
}
else
{
return (card_a->kind - card_b->kind);
}
}

/**
* sort_deck - Sorts a deck of cards.
* @deck: Pointer to a pointer of the deck's head node.
*/
void sort_deck(deck_node_t **deck)
{
size_t size = 0;
size_t i;
deck_node_t *current = *deck;
deck_node_t **node_array;
/* Calculate the size of the deck */
while (current != NULL)
{
size++;
current = current->next;
}

/* Create an array of pointers to deck nodes */

node_array = (deck_node_t **)malloc(size *sizeof(deck_node_t *));
if (!node_array)
{
/* Handle memory allocation error */
return;
}

/* Fill the array with pointers to deck nodes */
current = *deck;
for (i = 0; i < size; i++)
{
node_array[i] = current;
current = current->next;
}

/* Use qsort to sort the array of pointers */
qsort(node_array, size, sizeof(deck_node_t *), compare_cards);

/* Reconstruct the sorted deck using the sorted array */
*deck = node_array[0];
for (i = 0; i < size - 1; i++)
{
node_array[i]->next = node_array[i + 1];
node_array[i + 1]->prev = node_array[i];
}
node_array[size - 1]->next = NULL;

free(node_array);
}

