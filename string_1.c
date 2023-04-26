#include "main.h"

/**
 * string_concat - concatenate two strings together
 * @output_str: pointer to the destination string
 * @input_str: pointer to the source
 *
 * Return: pointer to the concatenated string
 */
char *string_concat(char *output_str, const char *input_str)
{
	char *output_ptr = output_str;

	while (*output_ptr != '\0')
	{
		output_ptr++;
	}
	while (*input_str != '\0')
	{
		*output_ptr++ = *input_str++;
	}
	*output_ptr = '\0';
	return (output_str);
}
/**
 * search_char - searches the target string for a given char
 * @target_str: a pointer to the string to search for the char
 * @target_char: charachter to search str
 *
 * Return: a pointer to a character
 */
char *search_char(const char *target_str, int target_char)
{
	while (*target_str != '\0')
	{
		if (*target_str == target_char)
		{
			return ((char *)target_str);
		}
		target_str++;
	}
	if (target_char == '\0')
	{
		return ((char *)target_str);
	}
	return (NULL);
}
