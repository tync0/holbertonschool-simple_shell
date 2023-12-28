#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 100
extern char **environ;
int main(void);
void pre_execute(char *command, char *tmp, int *status);
int execute(char *command);
char **split(char *input);
void free_arr(char **arr);
#endif

