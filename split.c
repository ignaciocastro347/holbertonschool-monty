#include "monty.h"
/**
 * split - create an array of strings from a string separated by chars
 * @buffer: string value to delimit
 * @delim: string with chars which ar delimiters
 * Return: array of string
 */
char **split(char *buffer, char *delim)
{
	char **list = NULL;
	char *token = NULL;
	char *dbuffer = NULL;
	int i = 0, amount_tokens = 0;

	if (!buffer)
		return (NULL);
	amount_tokens = count_tokens(buffer, delim);
	list = malloc(sizeof(char *) * (amount_tokens + 1));

	if (!list)
		return (NULL);
	dbuffer = strdup(buffer);
	token = strtok(dbuffer, delim);
	while (token)
	{
		list[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	list[i] = NULL;
	free(dbuffer);
	return (list);
}
/**
 * count_tokens - Count tokens
 * @str: String
 * @delims: Delimiters
 * Return: Number of tokens
*/
int count_tokens(char *str, char *delims)
{
	int counter = 0, i = 0, j = 0;
	int prev_is_delim = 0;

	for (; str[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (str[i] == delims[j])
			{
				if (!prev_is_delim)
				{
					if (i != 0)
						counter++;
					prev_is_delim = 1;
				}
				break;
			}
			else if (!delims[j + 1] && prev_is_delim)
				prev_is_delim = 0;
		}
	}
	if (i != 0 && !prev_is_delim)
		counter++;
	return (counter);
}

/**
 * free_string_list - free memory allocated in an array of strings
 * @list: array of strings
 * Return: 0 on success, 1 on failure
 */
int free_string_list(char **list)
{
	int i = 0;

	while (list[i])
		free(list[i++]);
	free(list);
	return (0);
}