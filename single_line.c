#include "main.h"

/**
 * single_line - function that runs the shell in single line mode
 * Return: 1 on success, -1 on failure
 */
int single_line(void)
{
char *command = malloc(SIZE), **argv = malloc(SIZE * sizeof(char *));
size_t size = SIZE;

if (command == NULL || argv == NULL)
return (-1);
getline(&command, &size, stdin);
tokens(command, argv);
if (execve(argv[0], argv, NULL) == -1)
perror("Error: ");
return (1);
}
