#include "monty.h"
/**
* get_op_func - seach a function
* @s: is a pointer
* Return: Always
*/

int (*get_op_func(char *s))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push_opcode},
		/* {"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},*/
		{NULL, NULL}
	};

	while (!opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}
	return(NULL);
}