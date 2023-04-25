#include "main.h"

/**
 * Handles command lines with arguments.
 *
 * @param cmd The command and arguments to execute.
 * @param envp The array of environment variables.
 */
void handle_cmd_args(char *cmd, char *envp[]) {
    pid_t pid = fork();
    int cmd_status;

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // child process
        char *args[MAX_CMD_LEN / 2 + 1];
        int i = 0;

        args[i] = strtok(cmd, " ");
        while (args[i] != NULL && i < MAX_CMD_LEN / 2) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (execve(args[0], args, envp) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        // parent process
        if (waitpid(pid, &cmd_status, 0) == -1) {
            perror("waitpid");
            exit(1);
        }
    }
}
