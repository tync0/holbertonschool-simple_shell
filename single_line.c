#include "main.h"

/**
 * single_line - function that runs the shell in single line mode
 * Return: 1 on success, -1 on failure
 */
int single_line(void)
{
char *command = malloc(SIZE), **argv = malloc(SIZE * sizeof(char *)), *new_command = malloc(SIZE);
int i = 0;
size_t size = SIZE;

if (command == NULL || argv == NULL || new_command == NULL)
return (-1);
getline(&command, &size, stdin);
if (c_trim(command, new_command) == 0)
{
	return (0);
}
tokens(command, argv);
while (argv[i])
{
    if (execve(argv[0], argv, NULL) == -1)
    perror("Error: ");
    i++;
}

return (1);
}
