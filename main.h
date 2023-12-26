#ifndef MAIN_H
#define MAIN_H
#define SIZE 100
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void free_elements(char **av);
void run_process(int id, char **str);

#endif
