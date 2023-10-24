#include "sort.h"

/**
 * swap_node - swap two nodes in doubly-linked list.
 * @p: ptr to head of  doubly-linked list.
 * @n1: A ptr to first node to swap.
 * @n2: second node to swap.
 */
void swap_node(listint_t **p, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*p = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sortdoubly linked list of ints using insertion
 * @list: ptr to the head of a doubly-linked list of ints
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_node(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
