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
 * add_node_to_beg - add a new node at the beggining of a list
 * @head: linked list
 * @n: int value
 * Return: pointer to a linked list
 */
stack_t *add_node_to_beg(stack_t **head, const int n)
{
	stack_t *new = NULL;

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

/**
 * print_last_node - print the top element of stack
 * @h: list
 */
void print_last_node(const stack_t *h)
{

	if (&h->n != NULL)
		printf("%d\n", h->n);
}

/**
 * pop_last_node - delete last node
 * @head: dlinked list
 */
void pop_last_node(stack_t **head)
{
	stack_t *first = (*head);

	*head = first->next;
	if (*head)
		(*head)->prev = NULL;
	free(first);
}
/**
 * swap_last_nodes - swap last two nodes from dlinked list
 * @head: dlinked list
 */
void swap_last_nodes(stack_t *head)
{
	stack_t *first = head;
	stack_t *second = head->next;
	int temp;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
