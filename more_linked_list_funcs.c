#include "monty.h"
/**
 * add_last_nodes - add last two nodes from dlinked list
 * @head: dlinked list
 */
void add_last_nodes(stack_t **head)
{
	stack_t *first = *head;
	stack_t *second = (*head)->next;

	second->n = first->n + second->n;
	second->prev = NULL;
	*head = second;
	free(first);
}

/**
 * free_dlistint - free a dlinked list
 * @head: dlinked list
 */
void free_dlistint(stack_t *head)
{
	stack_t *aux = NULL;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

/**
 * nop_opcode - doesn´t do anything
 */
void nop_opcode(void)
{}
