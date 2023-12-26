#include "main.h"

/**
 * interactive_mode - function that runs the shell in interactive mode
 * Return: 1 on success, -1 on failure
 */

int interactive_mode(void)
{
char *command, **argv;
size_t size = SIZE, status = 1;
int read;
pid_t pid;

command = malloc(SIZE);
argv = malloc(SIZE * sizeof(char *));
while (status)
{
	if (command == NULL || argv == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	read = getline(&command, &size, stdin);
	if (*command == '\n')
		continue;
	if (read == -1)
	{
		free(command);
		continue;
	}
	tokens(command, argv);
	if (!argv[0])
		break;
	pid = fork();
	status = execute(argv, pid);
	if (status == 0)
	{
		free(command);
		free(argv);
		exit(0);
	}
}
return (1);
}
