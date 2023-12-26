#include "main.h"

/**
 * single_line - function that runs the shell in single line mode
 * Return: 1 on success, -1 on failure
 */
int single_line(void)
{
char *command = malloc(SIZE), **argv = malloc(SIZE * sizeof(char *)),
*new_command = malloc(SIZE);
int i = 0;
pid_t pid;
size_t size = SIZE;
char **av = malloc(100 * sizeof(char *));

if (command == NULL || argv == NULL || new_command == NULL)
return (-1);
getline(&command, &size, stdin);
if (c_trim(command, new_command) == 0)
{
free(argv);
free(command);
free(new_command);
return (0);
}
argv[0] = "/bin/ls";
argv[1] = NULL;
tokens(command, av);
while (av[i])
{
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error: ");
	}
	else
		wait(NULL);
	i++;
}

return (1);
}
