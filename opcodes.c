#include "monty.h"
/**
* push_opcode - execute a push function
* @stack: is a pointer to a doubly linked list
* @line_number: a counter of read lines of file
* Return: Always
*/
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	char *token = NULL;
	/**if (isdigit(global_n_value) == 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		n = atoi(global_n_value);*/
	token = strtok(NULL, " \t\r");
	if (!token)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	if (!n && strcmp(token, "0") != 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_node_to_beg(stack, n);
}

void pall_opcode(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	print_nodes(*stack);
}
