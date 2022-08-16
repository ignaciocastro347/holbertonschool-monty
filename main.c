#include "monty.h"
/**
 * main - Monty files interpreter
 * @argc: amount of arguments
 * @argv: list of arguments 
 * Return: void
 */

int main (int argc, char **argv)
{
	char **lines = NULL;
	char **words = NULL;
	int i = 0, fd = 0, len = 0;
	int j = 0;
	char buff[1024];
	char *dup = NULL, *dup2 = NULL;
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);

	/* Reading file */
	while ((len = read(fd, buff, sizeof(buff))) > 0)
	{
		dup = strdup(buff);
		/* Tokenizing line by line */
		lines = split(dup, "\n");
		i = 0;
		while (lines[i])
		{
			dup2 = strdup(lines[i]);
			/* Tokenizinig word by word */
			words = split(dup2, " ");
			j = 0;
			while (words[j])
			{
				printf("%s\n", words[j]);
				j++;
			}
			i++;
		}
	}
	
	if (len == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}