#include "main.h"
/**
 * main - main function of the shell
 * Return: returns 0 on success
 */
int main(void)
{
	char *command, *tmp = NULL;
	int read, status = 0;
	size_t size;

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
		pre_execute(command, tmp, &status);
	}
	return (status);
}
/**
 * exit_and_env - handle exit and env function
 * @command: command
 * @status: status
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
