#include "main.h"
/**
 * get_path - gets the path of a command
 * @arr: array of commands
 * @command: command
 * Return: returns the path of the command
*/
char *get_path(char **arr, char *command)
{
	struct  stat st;
	char *path = getenv("PATH"), *copyenv = NULL, *token = NULL, *f_path = NULL;

	if (path == NULL || strlen(path) == 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
		free(command);
		free_arr(arr);
		exit(127);
	}
	copyenv = strdup(path);
	token = strtok(copyenv, ":");
	f_path = malloc(sizeof(char) * SIZE);
	while (token != NULL)
	{
		snprintf(f_path, SIZE, "%s/%s", token, arr[0]);
		if (stat(f_path, &st) == 0)
		{
			free(copyenv);
			return (f_path);
		}
		token = strtok(NULL, ":");
	}
	fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
	free(command);
	free(copyenv);
	free(f_path);
	free_arr(arr);
	exit(127);
}
