#include "main.h"

/**
 * execute_builtin - Executes a built-in command
 * specified by the given command string.
 *
 * @cmd: The command string to execute
 *
 * Return: void
 */

void execute_builtin(char *cmd)
{
	/* If the command is "exit", exit the program */
	if (strcmp(cmd, "exit") == 0)
	{
	exit(EXIT_SUCCESS);
	}
}
