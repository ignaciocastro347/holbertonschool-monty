#include "monty.h"
/**
 * add_node_to_end - add a node to the end of a linked list
 * @head: dlinked list
 * @n: int value
 * Return: pointer to a dlinked list
 */
stack_t *add_node_to_end(stack_t **head, const int n)
{
	stack_t *aux, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head)
	{
		aux = *head;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
		return (new);
	}
	new->prev = NULL;
	*head = new;
	return (new);
}
