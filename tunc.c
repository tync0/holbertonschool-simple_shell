#include "main.h"
/**
 * run_process - run process
 * @str: val
 * @id: val
 * Return: Always 0
 */
void run_process(int id, char **str)
{
	if (id == 0)
	{
		if (execve(str[0], str, NULL) == -1)
			perror("Error: ");
	}
	else if (id == -1)
	{
		perror("fork: ");
		return;
	}
	else
		wait(NULL);
}
/**
 * free_elements - free elements
 * @av: val
 * @index: val
 * @str: val
 * Return: Always 0
 */
void free_elements(char **av)
{
	int id;

	for(id = 0 ; !av[id] ; id++)
		free(av[id]);
	free(av);
}
/**
 * main - main function
 * Return: Always 0
 */
int main(void)
{
	size_t x = SIZE;
	char *buf = NULL, *cmd, **av;
	int ex, i = 0;

	while (1)
	{
		av = malloc(SIZE * sizeof(char *));
		if (!av)
                	exit(98);
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (getline(&buf, &x, stdin) == -1)
		{
                        free(buf);
			free_elements(av);
			break;
		}
		if (strcmp(buf, "\n") == 0)
		{
			free_elements(av);
			continue;
		}
		cmd = strtok(buf, " \t\n");
		while (cmd)
		{
			av[i++] = strdup(cmd);
			cmd = strtok(NULL, " \t\n");
		}
		if (!av || !av[0])
		{
			free(cmd);
			free(buf);
			free_elements(av);
			break;
		}
		ex = fork();
		
		run_process(ex, av);
		free(cmd);
		free(buf);
		free_elements(av);
		i = 0;
	}
	return (0);
}
