#include "monty.h"
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
 * pint_opcode - execute a pint function
 * @stack: is a pointer to a doubly linked list
 * @line_number: a counter of read lines of file
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	print_last_node(*stack);
}

/**
 * pop_opcode - execute a pop function
 * @stack: is a pointer to a doubly linked list
 * @line_number: a counter of read lines of file
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop_last_node(stack);
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
