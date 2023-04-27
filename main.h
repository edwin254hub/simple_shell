#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 120

extern char **environ;

char *tokenize_string(char *input_string, const char *separator);
char **separate_args(char *cmd);
char **get_cmd(void);
void run_exec(char **args);
char *locate_exec(char *cmd);
int find_exec_path(char *directory_list, char *cmd, char *absolute_path);
void terminate_shell(char **args);
char *search_char(const char *target_str, int target_char);
char *string_concat(char *output_str, const char *input_str);
int string_length(const char *str);
int string_compare(char *stringA, char *stringB);
void string_copy(char *source, char *destination);
char *duplicate_str(const char *str_source);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
#endif /*MAIN_H_*/
