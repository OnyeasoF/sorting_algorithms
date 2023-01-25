#include "sort.h"

void swap_front_node(listint_t **list, listint_t **tail, listint_t **start);
void swap_back_node(listint_t **list, listint_t **tail, listint_t **start);

/**
 * cocktail_sort_list - bidirectional sorting func that sort doubly linked list
 * @list: double pointer to the head node
 *
 * Description: sorts a list using cocktail sort - sorting algotithm
 *		that extends bubble a variation of selection sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *tail;
	bool shaken = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tail = *list;

	while (tail->next != NULL)
		tail = tail->next;

	while (shaken)
	{
		shaken = false;
		for (start = *list; start != tail; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_front_node(list, &tail, &start);
				print_list((const listint_t *)*list);
				shaken = true;
			}
		}

		for (start = tail->prev; start != *list; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_back_node(list, &tail, &start);
				print_list((const listint_t *)*list);
				shaken = true;
			}
		}
	}
}


/**
 * swap_front_node - swaps  nodes of a doubly linked list with the ones ahead
 * @list: double pointer to the head of the doubly linked list
 * @tail: double pointer to the tail of the doubly linked list
 * @start: souble pointer to the start of the doubly linked list
 */

void swap_front_node(listint_t **list, listint_t **tail, listint_t **start)
{
	listint_t *trav;

	trav = (*start)->next;
	if ((*start)->prev != NULL)
		(*start)->prev->next = trav;
	else
		*list = trav;
	trav->prev = (*start)->prev;
	(*start)->next = trav->next;
		if (trav->next != NULL)
			trav->next->prev = *start;
		else
			*tail = *start;
	(*start)->prev = trav;
	trav->next = *start;
	(*start) = trav;
}


/**
 * swap_back_node - swaps  nodes of a doubly linked list with the ones behind
 * @list: double pointer to the head of the doubly linked list
 * @tail: double pointer to the tail of the doubly linked list
 * @start: souble pointer to the start of the doubly linked list
 */

void swap_back_node(listint_t **list, listint_t **tail, listint_t **start)
{
	listint_t *trav = (*start)->prev;

	if ((*start)->next != NULL)
		(*start)->next->prev = trav;
	else
		*tail = trav;
	trav->next = (*start)->next;
	(*start)->prev = trav->prev;
	if (trav->prev != NULL)
		trav->prev->next = *start;
	else
		*list = *start;
	(*start)->next = trav;
	trav->prev = (*start);
	(*start) = trav;
}
