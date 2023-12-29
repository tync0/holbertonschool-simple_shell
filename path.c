#include "main.h"
/**
 * get_path - gets the path of a command
 * @c_path: command path
 * @f_path: full path
 * Return: returns the full path of a command
*/
char *get_path(char **arr, char *command)
{
	struct  stat st;
	char *path = getenv("PATH");
	char *copyenv = strdup(path);
	char *token = strtok(copyenv, ":");
	char *f_path = malloc(sizeof(char) * SIZE);

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
	free(path);
	free_arr(arr);
	exit(127);
}
