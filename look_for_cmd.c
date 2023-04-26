#include "main.h"

/**
 * find_exec_path - search for the path of the command in the directories
 *
 * @directory_list: a copy of the PATH environment variable
 * @cmd: the name of the command to search for
 * @absolute_path: a buffer to store the full path of the executable
 * Return: 1 if cmd_match, 0 if not
 */

int find_exec_path(char *directory_list, char *cmd, char *absolute_path)
{
	char *dir;
	int cmd_match;

	cmd_match = 0;

	dir = tokenize_string(directory_list, ":");
	while (dir != NULL)
	{

		string_copy(absolute_path, dir);
		string_concat(absolute_path, "/");
		string_concat(absolute_path, cmd);

		if (access(absolute_path, X_OK) == 0)
		{
			cmd_match = 1;
			break;
		}
		dir = tokenize_string(NULL, ":");
	}
	return (cmd_match);
}
