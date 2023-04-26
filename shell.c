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
	exec_env(cmd);
	execute_builtin(cmd);
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
<<<<<<< HEAD
	char *full_path = resolve_path(cmd, envp);

	if (full_path == NULL)
	{
		printf("%s: command not found\n", cmd);
		return;
	}

	pid_t pid = fork();
	int cmd_status;
=======
	char full_cmd[MAX_CMD_LEN];

	if (find_executable(cmd, full_cmd) == -1)
	{
		printf("Command not found: %s\n", cmd);
		set_last_cmd_status(1);
	return;
	}

	pid_t pid = fork();
>>>>>>> da62079d3690ace17e4c12801b3b914d63a00a62

	if (pid < 0)
	{
		perror("fork");
		set_last_cmd_status(1);
	return;
	}
	else if (pid == 0)
	{
<<<<<<< HEAD
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
=======
	char *args[] = { full_cmd, NULL };

	if (execve(full_cmd, args, envp) == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		set_last_cmd_status(1);
	exit(1);
	}
	}
	else
	{
	if (waitpid(pid, &last_cmd_status, 0) == -1)
	{
		perror("waitpid");
		set_last_cmd_status(1);
	return;
	}
	}

>>>>>>> da62079d3690ace17e4c12801b3b914d63a00a62
}
#endif /* MY_SHELL_H */
