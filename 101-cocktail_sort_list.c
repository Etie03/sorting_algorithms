#include "sort.h"

/**
 * swap_node - swaps a node
 * @list: double pointer
 * @node: the node
 *
 * Return: void
 */
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char m = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (m != 0)
	{
		m = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap_node(list, temp);
				m = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (m == 0)
			break;
		m = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_node(list, temp->prev);
				m = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
