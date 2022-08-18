#include "monty.h"

/**
 * get_op_func - seach a function
 * @s: is a pointer
 * @n: is a int
 * Return: Always
 */

void (*get_op_func(char *s, unsigned int n))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}
	if (!opcodes[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", n, s);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
