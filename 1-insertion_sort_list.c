#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion Sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *insertion = current;
        int value = insertion->n;

        while (insertion->prev != NULL && insertion->prev->n > value)
        {
            insertion->n = insertion->prev->n;
            insertion = insertion->prev;
            print_list(*list);
        }

        insertion->n = value;
        current = current->next;
    }
}

