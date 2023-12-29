#include "main.h"
/**
 * main - main function of the shell
 * Return: returns 0 on success
 */
int main(void)
{
	char *command, *tmp = NULL, **arr = malloc(sizeof(char *) * SIZE);
	char *path;
	int read, status = 0;
	size_t size;

	if (!arr)
	{
		perror("Malloc Error: ");
		exit(98);
	}
	while (1)
	{
		command = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);
		read = getline(&command, &size, stdin);
		if (read == -1)
		{
			free(command);
			break;
		}
		command[read - 1] = '\0';
		tmp = command;
		if (command == NULL)
		{
			free(tmp);
			break;
		}
		while (command[0] == ' ' || command[0] == '\t')
			command++;

		if (command[0] == '\n' || command[0] == '\0')
		{
			free(tmp);
			continue;
		}
		if (exit_and_env(command, &status))
			continue;
		arr = split(command);
		printf("command: %s\n", command);
		printf("arr: %s\n", arr[0]);
		if (!arr)
		{
			perror("Error");
			exit(1);
		}
		path = get_path(arr, command);
		printf("path: %s\n", path);
		if (!path)
		{
			path = strdup("");
			command = strdup("/bin/ls");
		}
		pre_execute(command, tmp, &status, arr);
	}
	return (status);
}
/**
 * exit_and_env - handle exit and env function
 * @command: command
 * @status: status
 * Return: True if is env otherwise False
 */
bool exit_and_env(char *command, int *status)
{
	if (strcmp(command, "env") == 0)
	{
		*status = 0;
		print_env();
		free(command);
		return (true);
	}
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(*status);
	}
	return (false);
}
