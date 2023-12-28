#include "main.h"

/**
 * split - splits a string into an array of strings
 * @command: string to split
 * Return: returns an array of strings
 */
char **split(char *command)
{
	char *token, **tokens;
	int i = 0;

	tokens = malloc(sizeof(char *) * SIZE);
	if (!tokens)
	{
		perror("Malloc Error: ");
		exit(98);
	}
	token = strtok(command, " \t\n");
	while (token)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * pre_execute - prepares and executes a command
 * @command: command to execute
 * @tmp: temporary variable for memory management
 * @status: status
 * Return: void
 */
void pre_execute(char *command, char *tmp, int *status)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		free(command);
		perror("Error");
	}
	else if (pid == 0)
	{
		execute(command);
		free(tmp);
		exit(0);
	}
	else
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		free(tmp);
	}
}

/**
 * execute - executes a command
 * @command: command to execute
 * Return: returns 0 on success
 */
int execute(char *command)
{
	char **arr = split(command);

	if (arr == NULL)
	{
		perror("Error");
		exit(1);
	}
	if (execve(arr[0], arr, environ) == -1)
	{
		perror("Error execve");
		free_arr(arr);
		free(command);
		exit(1);
	}
	free_arr(arr);
	free(command);
	return (0);
}

/**
 * free_arr - frees an array of strings
 * @arr: array to free
 * Return: void
 */
void free_arr(char **arr)
{
	int i = 0;

	while (arr[i])
		free(arr[i++]);
	free(arr);
}

