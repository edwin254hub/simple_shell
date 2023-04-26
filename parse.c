#include "main.h"

/**
 * parse_input - tokeznizes input string into array of strings
 * @input: user input
 * Return: 0, always
 */
char **parse_input(char *input)
{
	int buffer_size = BUFFER_SIZE;
	int index = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	token = strtok(input, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		if (index >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
		}
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[index] = NULL;
	return (tokens);
}

