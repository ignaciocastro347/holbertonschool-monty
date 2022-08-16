#include "monty.h"

/**
* main - Monty files interpreter
* @argc: amount of arguments
* @argv: list of arguments 
* Return: void
*/

int main (int argc, char **argv)
{
	int finput = 0, len = 0;
	char buff[1024], *line;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	finput = fopen(argv[1], O_RDONLY);
	line = fgets(buff[1024], finput, " \n")
	while (line)
	{
		token = strtok()
	}
	if (len == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
* get_op_func - seach a function
* @s: is a pointer
* Return: Always
*/

int *get_op_func (char *s)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push_opcode},
		/**{"pall", pall_opcode},
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
