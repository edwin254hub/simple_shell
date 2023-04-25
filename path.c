#include "main.h"

/**
 * find_executable - Searches for an executable file
 * in the directories listed in the PATH environment variable.
 * @file: The name of the executable file to search for.
 * @result: A buffer to store the full path to the executable file.
 * Return: 0 if the executable file was found, -1 otherwise.
 */
int find_executable(const char *file, char *result)
{
	const char *path = getenv("PATH");

	if (!path)
	{
		return (-1);
	}
	char *paths[MAX_PATHS];
	int num_paths = 0;

	const char *sep = ":";
	char *token = strtok((char *) path, sep);

	while (token)
	{
		if (num_paths >= MAX_PATHS)
		{
			break;
		}
		paths[num_paths++] = token;
		token = strtok(NULL, sep);
	}
	struct stat st;

	for (int i = 0; i < num_paths; i++)
	{
		char path[MAX_PATH_LEN + 1];

		snprintf(path, MAX_PATH_LEN, "%s/%s", paths[i], file);
		if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			strcpy(result, path);
			return (0);
		}
	}
	return (-1);
}

