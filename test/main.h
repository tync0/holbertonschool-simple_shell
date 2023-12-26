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
int shell(void);
void tokens(char *command, char **argv);
#endif /* MAIN_H */
