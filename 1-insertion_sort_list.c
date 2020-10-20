#include "sort.h"
/**
 * insertion_sort_list - insertion sort list algorthms
 * @list: list pointer
 * Return: No Return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *aux_node, *temp_node;

	if (!list || !(*list))
		return;
	current_node = *list;

	if (!(current_node->next))
		return;
	while (current_node->next)
	{
		aux_node = current_node->next;
		if (current_node->n > aux_node->n)
		{
			temp_node = current_node;
			while (temp_node && temp_node->n > aux_node->n)
			{
				temp_node->next = aux_node->next;
				if (temp_node->next)
					temp_node->next->prev = temp_node;
				aux_node->prev = temp_node->prev;
				if (aux_node->prev)
					aux_node->prev->next = aux_node;
				else
					*list = aux_node;
				temp_node->prev = aux_node;
				aux_node->next = temp_node;
				print_list(*list);
				temp_node = aux_node->prev;
			}
			continue;
		}
		current_node = current_node->next;
	}
}
