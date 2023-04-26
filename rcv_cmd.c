#include "main.h"

/**
 * get_cmd - gets the cmd to stdin
 *
 * Return: a ptr to str where the command is found
 */
char **get_cmd(void)
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	ssize_t nos_read;

	char **args = malloc(sizeof(char *) * 3);
	int i = 0;
	char *token;

	nos_read = getline(&cmd, &cmd_len, stdin);
	if (nos_read == -1)
	{
		write(1, "\n", 1);
		exit(0);
	}
	cmd[nos_read - 1] = '\0';

	token = tokenize_string(cmd, " ");
	while (token != NULL && i < 2)
	{
		args[i++] = token;
		token = tokenize_string(NULL, " ");
	}
	args[i] = NULL;

	if (string_compare(cmd, "exit") == 0)
	{
		terminate_shell(args);
		free(cmd);
		exit(0);
	}
	return (args);
}
