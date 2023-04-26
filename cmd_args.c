#include "main.h"

void read_cmd(char *cmd);
void execute_cmd(char *cmd, char *envp[]);

/**
 * main - function that starts the shell.
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 * @envp: array of environment variables.
 * Return: 0, always
 */
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
 * read_cmd - reads the command from the user.
 *
 * @cmd: The command to execute.
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
	cmd[strcspn(cmd, "\n")] = '\0';
}
/**
 * execute_cmd - executes a command.
 * @envp: an array of environment.
 * @cmd: The command to execute.
 */

void execute_cmd(char *cmd, char *envp[])
{
	pid_t pid = fork();
	int cmd_status;

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}

	if (pid == 0)
	{
		/* child process */
		char *args[MAX_CMD_LEN / 2 + 1];
		int i = 0;

		args[i] = strtok(cmd, " ");

		while (args[i] != NULL && i < MAX_CMD_LEN / 2)
		{
			i++;
			args[i] = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (execve(args[0], args, envp) == -1)
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
}
