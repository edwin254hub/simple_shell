#include "main.h"

/**
 * string_length - counts the length of a string
 * @str: the string to measure
 * Return: length of string
 */
int string_length(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * string_compare - Compares two strings lexicographically
 * @stringA: first string
 * @stringB: second string
 * Return: 0 if the two strings are equal, a negative integer if the 1st
 * non-matching character in @string1 is less than the corresponding char
 * in @string2, and a positive integer otherwise.
 */
int string_compare(char *stringA, char *stringB)
{
	while (*stringA && *stringB && *stringA == *stringB)
	{
		stringA++;
		stringB++;
	}
	return (*stringA - *stringB);
}
/**
 * string_copy - copy string into other string
 * @source: string used to copy
 * @destination: the new copy
 */
void string_copy(char *destination, char *source)
{
	int i = 0;

	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
/**
 * duplicate_str - create a duplicate of a string
 * @str_source: the string to duplicate
 * Return: a pointer to the new string duplicate
 */
char *duplicate_str(const char *str_source)
{
	size_t i;
	size_t len = string_length(str_source) + 1;
	char *copied_str = malloc(len);

	if (copied_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		copied_str[i] = str_source[i];
	}
	return (copied_str);
}
