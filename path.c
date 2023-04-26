#include "main.h"

/**
 * resolve_path - Searches for full path of give command
 * in the directories listed in the PATH environment variable.
 * @cmd: command
 * @envp: an array of pointers
 * Return: 0 always
 */
char *resolve_path(char *cmd, char *envp[])
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	char *full_path = (char *) malloc(strlen(token) + strlen(cmd) + 2);

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}

