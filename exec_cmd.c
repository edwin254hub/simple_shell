#include "main.h"

/**
 * run_exec - runs an executable specified by the command
 *
 * @args: an array of pointers containing the command
 * and arguments to be executed
 */

void run_exec(char **args)
{
	char *absolute_path;

	if (args[0] == NULL)
	{
		return;
	}

	if (args[0][0] == '/')
	{
		absolute_path = args[0];
	} else
	{
		absolute_path = locate_exec(args[0]);
	}

	if (absolute_path != NULL)
	{
		if (fork() == 0)
		{
			execve(absolute_path, args, environ);
			perror(absolute_path);
			exit(1);
		} else
		{
			wait(NULL);
		}
		if (absolute_path != args[0])
		{
			free(absolute_path);
		}
	} else
	{
		char *cmd_name = args[0];
		char *program = ": command not found\n";

		write(STDERR_FILENO, cmd_name, string_length(cmd_name));
		write(STDERR_FILENO, program, string_length(program));
	}
}
