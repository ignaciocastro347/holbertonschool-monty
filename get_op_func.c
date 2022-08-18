#include "monty.h"

/**
 * get_op_func - seach a function
 * @s: is a pointer
 * Return: Always
 */

void (*get_op_func(char *s, unsigned int line_number))(stack_t **pepe, unsigned int h)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
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
		dprintf(STDERR_FILENO, "L%d: unknowdn instruction %s\n", line_number, s);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
