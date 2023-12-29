#include "main.h"
/**
 * get_path - gets the path of a command
 * @arr: array of args
 * @f_path: full path
 * @command: command
 * Return: returns the full path of a command
*/
char *get_path(char **arr, char *command)
{
	char *f_path = malloc(100);
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	if (!f_path)
		exit(98);
	while (token != NULL)
	{
		printf("token: %s\n", token);
		sprintf(f_path, "%s/%s", token, arr[0]);
		printf("f_path: %s\n", f_path);
		if (access(f_path, F_OK) == 0)
		{
			printf("f_path: %s\n", f_path);
			return (strdup(f_path));
		}
		token = strtok(NULL, ":");
	}
	if (arr[0][0] == '/' || arr[0][0] == '.')
		return (arr[0]);
	fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
	free(command);
	free(path);
	free_arr(arr);
	exit(127);
}
