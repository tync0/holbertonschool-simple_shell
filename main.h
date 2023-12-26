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
#include <sys/wait.h>
int interactive_mode();
void tokens(char *command, char **argv);
int execute(char **argv, pid_t pid);
int c_trim(char *str, char *str1);
#endif /* MAIN_H */
