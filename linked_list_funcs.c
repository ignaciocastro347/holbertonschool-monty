#include "monty.h"

/**
 * print_nodes - prints all the elements of a dlistint_t
 * @h: list
 * Return: the number of nodes
 */
size_t print_nodes(const stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		if (&h->n != NULL)
			printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

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

/**
 * add_node_to_beg - add a new node at the beggining of a list
 * @head: linked list
 * @n: int value
 * Return: pointer to a linked list
 */
stack_t *add_node_to_beg(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	new->prev = NULL;
	*head = new;
	return (new);
}

