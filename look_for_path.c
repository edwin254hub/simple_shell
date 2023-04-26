#include "main.h"

/**
 * locate_exec - searches for the path of the given command
 *
 * @cmd: pointer to a string containing the name of the cmd
 * Return: NULL if successful
 */

char *locate_exec(char *cmd)
{
	char *path, *directory_list, *absolute_path;
	int cmd_match = 0;

	path = getenv("PATH");
	if (path == NULL)
	{
		perror("getenv");
		return (NULL);
	}
	directory_list = duplicate_str(path);
	if (directory_list == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	absolute_path = malloc(string_length(path) + string_length(cmd) + 2);
	if (absolute_path == NULL)
	{
		perror("malloc");
		free(directory_list);
		return (NULL);
	}
	cmd_match = find_exec_path(directory_list, cmd, absolute_path);
	free(directory_list);
	if (!cmd_match)
	{
		free(absolute_path);
		absolute_path = NULL;
	}
	return (absolute_path);
}
