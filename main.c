#include "monty.h"

/**
 * main - Monty files interpreter
 * @argc: amount of arguments
 * @argv: list of arguments 
 * Return: void
 */

int main (int argc, char **argv)
{
	char buff[1024];
	FILE *fp;
	char *line = NULL, **tokens = NULL;
	int i;

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
		line = strtok(buff, "\n");
		tokens = split(line, " \t");
		i = 0;
		while (tokens[i])
			printf("%s\n", tokens[i++]);
	}
	return (0);
}
