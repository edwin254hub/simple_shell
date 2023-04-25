#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_CMD_LEN 1024
#define MAX_PATHS 1024
#define MAX_PATH_LEN 1024

void read_cmd(char *cmd);
void execute_cmd(char *cmd, char *envp[]);
int find_executable(const char *file, char *result);
int main(int argc, char *argv[], char *envp[]);
void execute_builtin(char *cmd);
void exec_env(char *cmd);
void handle_cmd_args(char *cmd, char *envp[]);

#endif /*MAIN_H_*/
