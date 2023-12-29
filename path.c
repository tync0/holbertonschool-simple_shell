#include "main.h"
/**
 * get_path - gets the path of a command
 * @c_path: command path
 * @f_path: full path
 * Return: returns the full path of a command
*/
char *get_path(char *c_path, char *f_path)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(f_path, SIZE, "%s/%s", token, c_path);
		if (access(f_path, F_OK) == 0)
			return (f_path);
		token = strtok(NULL, ":");
	}
	return (c_path);
}
