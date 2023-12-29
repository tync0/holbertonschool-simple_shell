#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#define SIZE 100
extern char **environ;
int main(void);
bool exit_and_env(char *command, int *status);
void pre_execute(char *command, char *tmp, int *status);
void execute(char **arr, char *command, char *path, int *status, char *tmp);
char **split(char *input);
void free_arr(char **arr);
void print_env(void);
char *get_path(char **arr, char *f_path, char *command);
#endif
