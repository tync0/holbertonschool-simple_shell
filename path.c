#include "main.h"
/**
 * get_path - gets the path of a command
 * @c_path: command path
 * @f_path: full path
 * Return: returns the full path of a command
*/
char *get_path(char **arr, char *f_path, char *command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(f_path, SIZE, "%s/%s", token, arr[0]);
		if (access(f_path, F_OK) == 0)
			return (f_path);
		token = strtok(NULL, ":");
	}
	if (arr[0][0] == '/' || arr[0][0] == '.')
		return (arr[0]);
	fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
	free(command);
	free_arr(arr);
	exit(127);
}
