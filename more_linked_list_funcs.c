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
 * @stack: is a pointer to a doubly linked list
 * @n: a counter of read lines of file
 */
void nop_opcode(stack_t **stack, unsigned int n)
{
	(void)stack;
	(void)n;
}

/**
 * push_opcode - execute a push function
 * @stack: is a pointer to a doubly linked list
 * @line_number: a counter of read lines of file
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int n = 0, i;
	char *token = NULL;

	token = strtok(NULL, " \t\r");
	if (!token)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; token[i]; i++)
	{
		if (token[i] == '-')
			return;
		if (isdigit(token[i]) == 0)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(token);
	if (!n && strcmp(token, "0") != 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_node_to_beg(stack, n);
}
