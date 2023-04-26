#include "main.h"

/**
 * main - Entry point for the mszshell program
 * Return: 0 on success
 */

int main(void)
{
	char **args;

	while (1)
	{
		write(STDOUT_FILENO, "shell$", 12);
		args = get_cmd();
		run_exec(args);
		free(args[0]);
		free(args);
	}
	return (0);
}
