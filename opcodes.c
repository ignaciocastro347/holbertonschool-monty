#include "monty.h"
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

/**
 * pall_opcode - execute a pall function
 * @stack: is a pointer to a doubly linked list
 * @line_number: a counter of read lines of file
 */

void pall_opcode(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	print_nodes(*stack);
}

/**
 * swap_opcode - execute a swap function
 * @stack: is a pointer to a doubly linked list
 * @line_number: a counter of read lines of file
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap_last_nodes(stack);
}

/**
 * add_opcode - execute an add function
 * @stack: is a pointer to a doubly linked list
 * @line_number: a counter of read lines of file
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_last_nodes(stack);
}

