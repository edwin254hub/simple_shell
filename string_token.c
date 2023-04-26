#include "main.h"

/**
 * tokenize_string - Tokenizes a string using a separator
 * @input_string: the string to tokenize
 * @separator: the token seperator
 * Return: pointer to token or NULL if there isn't further strings
 */
char *tokenize_string(char *input_string, const char *separator)
{
	static char *string_current_position;
	char *current_token = NULL;

	if (input_string)
		string_current_position = input_string;

	if (string_current_position == NULL)
		return (NULL);

	current_token = string_current_position;
	while (*string_current_position != '\0')
	{
		if (search_char(separator, *string_current_position) != NULL)
		{
			*string_current_position = '\0';
			string_current_position++;
			return (current_token);
		}
		string_current_position++;
	}
	if (current_token == string_current_position)
		return (NULL);
	return (current_token);
}
