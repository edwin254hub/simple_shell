#ifndef MY_SHELL_H
#define MY_SHELL_H

#include "main.h"
/**
 * main - function that starts the shell.
 *
 * argc: The number of command-line arguments.
 * argv: The array of command-line arguments.
 * envp: The array of environment variables.
 *
 * @cmd: The command to be processed.
 */
void read_cmd(char *cmd);
void execute_cmd(char *cmd, char *envp[]);

int main(int argc, char *argv[], char *envp[])
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		printf("> ");
		read_cmd(cmd);
		execute_cmd(cmd, envp);
	}

	return (0);
	}
/**
 * read_cmd - reads a command from the user.
 *
 *
 * @cmd: The command to be processed.
 */

void read_cmd(char *cmd)
{
	if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(1);
		}
	}

	/* remove trailing newline */
	cmd[strcspn(cmd, "\n")] = '\0';
}

/**
 * execute_cmd - executes a command.
 *
 * @cmd: The command to execute.
 *
 *
 * @envp: The environment variables.
 */

void execute_cmd(char *cmd, char *envp[])
{
	char *full_path = resolve_path(cmd, envp);

	if (full_path == NULL)
	{
		printf("%s: command not found\n", cmd);
		return;
	}

	pid_t pid = fork();
	int cmd_status;

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		/* child process */
		char *args[] = { full_path, NULL };

		if (execve(full_path, args, envp) == -1)
		{
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(1);
		}
	}
	else
	{
		/* parent process */
		if (waitpid(pid, &cmd_status, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
	free(full_path);
}
#endif /* MY_SHELL_H */
