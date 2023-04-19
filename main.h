#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#define MAX_CMD_LEN 1024

void read_cmd(char *cmd);
void execute_cmd(char *cmd, char *envp[]);


#endif /*MAIN_H_*/
