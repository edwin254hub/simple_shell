#include "main.h"


/**
 * exec_env - Executes the "env" command, which prints
 * out the current environment variables.
 *
 * @cmd: The command string to execute.
 *
 * Return: void.
 */
void exec_env(char *cmd)
{
	char **environ;
	/* If the command is "env", print out the environment */
	if (strcmp(cmd, "env") == 0)
	{
	char **env_ptr = environ;
	/* Loop through the list of envt and print them out */
	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
	}
}

