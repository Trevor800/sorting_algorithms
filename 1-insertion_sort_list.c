#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *next_node, *prev_node;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

curr = (*list)->next;
while (curr != NULL)
{
next_node = curr->next;
prev_node = curr->prev;

while (prev_node != NULL && prev_node->n > curr->n)
{
/* Swap curr and prev_node */
if (prev_node->prev != NULL)
prev_node->prev->next = curr;
if (curr->next != NULL)
curr->next->prev = prev_node;
prev_node->next = curr->next;
curr->prev = prev_node->prev;
curr->next = prev_node;
prev_node->prev = curr;

/* Update the head of the list if necessary */
if (curr->prev == NULL)
*list = curr;

print_list(*list);

prev_node = curr->prev;
}

curr = next_node;
}
}
