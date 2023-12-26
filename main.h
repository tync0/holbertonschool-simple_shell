#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define SIZE 100
extern char **environ;
int main(void);
int execute_command(char *command);
void execute(pid_t pid, char *command);
char **split(char *input);
void free_arr(char **arr);
#endif
