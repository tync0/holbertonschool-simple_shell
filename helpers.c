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
	char **arr, *path, *f_path = NULL;

	arr = split(command);
	if (command[0] == '/' || command[0] == '.')
		path = strdup(command);
	else
		path = get_path(arr, command);
	execute(arr, path, status, tmp);
}

/**
 * execute - executes a command
 * @command: command to execute
 * Return: returns 0 on success
 */
void execute(char **arr, char *path, int *status, char *tmp)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		free(tmp);
		perror("Error");
	}
	else if (pid == 0)
	{
		if (execve(path, arr, environ) == -1)
		{
			perror("Error execve");
			free_arr(arr);
			free(tmp);
			free(path);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		free(tmp);
	}
	free(path);	
	free_arr(arr);
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

/**
 * print_env - prints the environment
 * Return: void
*/
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
