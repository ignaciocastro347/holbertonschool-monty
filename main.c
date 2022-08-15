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
    char buff[1024];

    if (argc != 2)
    {
        write(STDERR_FILENO, "USAGE: monty file\n", 18);
        exit(EXIT_FAILURE);
    }

    finput = open(argv[1], O_RDONLY);
    while ((len = read(finput, buff, sizeof(buff))) > 0)
    {
        printf("%s\n", buff);
    }
    
    if (len == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

    return (0);
 }