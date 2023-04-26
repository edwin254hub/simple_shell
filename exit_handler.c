#include "main.h"

/**
 * terminate_shell - exit the shell with the given exit status
 * @args: an array of pointers to strings that contain the
 * user's input arguments
 */

void terminate_shell(char **args)
{
	int exit_code = 0;

	if (args[1] != NULL)
	{
		exit_code = atoi(args[1]);
	}
	free(args[0]);
	free(args);
	exit(exit_code);
}
