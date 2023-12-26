#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
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
void free_elements(char ***av)
{
	int id;

	for(id = 0 ; !(*av)[id] ; id++)
		free((*av)[id]);
	free(*av);
}
/**
 * main - main function
 * Return: Always 0
 */
int main(void)
{
	size_t x = 100;
	char *buf, *cmd, **av;
	int ex, i = 0;

	while (1)
	{
		buf = malloc(x);
		av = malloc(x * sizeof(char *));
		if (!buf || !av)
                	exit(98);
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		getline(&buf, &x, stdin);
		if (!buf)
			exit(98);
		if (strcmp(buf, "\n") == 0)
			continue;
		cmd = strtok(buf, " \t\n");
		while (cmd)
		{
			av[i++] = strdup(cmd);
			cmd = strtok(NULL, " \t\n");
		}
		if (!av[0])
			break;
		ex = fork();
		run_process(ex, av);
		free_elements(&av);
		free(buf);
		i = 0;
	}
	return (0);
}
