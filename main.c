#include "monty.h"

char *global_n_value = NULL;

/**
 * main - Monty files interpreter
 * @argc: amount of arguments
 * @argv: list of arguments
 * Return: void
 */

int main(int argc, char **argv)
{
	char buff[1024];
	FILE *fp;
	char *line = NULL, **tokens = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	void (*f)(stack_t **, unsigned int);

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, 1024, fp) != NULL)
	{
		line_number++;
		line = strtok(buff, "\n");
		if (!line)
			continue;
		tokens = split(line, " \t\r");
		global_n_value = tokens[1] ? tokens[1] : NULL;
		f = get_op_func(tokens[0], line_number);
		if (f)
			f(&stack, line_number);

		free_string_list(tokens);
	}

	free_dlistint(stack);
	fclose(fp);

	return (0);
}
