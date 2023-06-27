#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *insert = current;
        listint_t *prev = current->prev;

        while (prev != NULL && insert->n < prev->n)
        {
            /* Swap nodes */
            if (prev->prev != NULL)
                prev->prev->next = insert;
            if (insert->next != NULL)
                insert->next->prev = prev;

            prev->next = insert->next;
            insert->prev = prev->prev;

            insert->next = prev;
            prev->prev = insert;

            if (insert->prev == NULL)
                *list = insert;

            print_list(*list);

            prev = insert->prev;
        }

        current = current->next;
    }
}
