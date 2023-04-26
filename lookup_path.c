#include "main.h"

/**
 * lookup_path - searches directory specified in the PATH environment variable
 * @cmd: command
 * Return: 0 , always
 */
char *lookup_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir;
	char *full_pathname = malloc(1024);
	char *temp;
	int i = 0;

	dir = strtok(path, ":");

	while (dir != NULL)
	{
		sprintf(full_pathname, "%s/%s", dir, cmd);
		if (access(full_pathname, X_OK) != -1)
		{
			temp = malloc(strlen(full_pathname) + 1);
			strcpy(temp, full_pathname);
			return (temp);
		}
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

