#ifndef MAIN_H
#define MAIN_H
#define SIZE 100
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 100
extern char **environ;
char **split_line(char *command);
int execute(char *command);
void free_token(char **tokens);
#endif /* MAIN_H */
