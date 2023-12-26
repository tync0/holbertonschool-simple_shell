#include "main.h"

/**
 * split_line - splits a line into tokens
 * @command: line to split
 * Return: array of tokens
*/
char **split_line(char *command)
{
    char *token, **tokens;
    int i = 0;

    tokens = malloc(sizeof(char *) * SIZE);
    if (tokens == NULL)
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
 * execute - executes a command
 * @tokens: array of tokens
 * Return: 0 on success, -1 on failure
*/
int execute(char *command)
{
    char **tokens, *tmp;
    pid_t pid;
    int status;

    tokens = split_line(command);
    if (tokens == NULL)
        return (-1);
    pid = fork(); 
	if (pid == -1) 
	{
		free_token(tokens);
		return (-1);
	}
	else if (pid == 0)  
	{
		status = execve(tokens[0], tokens, environ);
	}
	else  
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status); 
    }
	free_token(tokens);
	return (status);
}

/**
 * free_token - frees an array of tokens
 * @tokens: array of tokens
 * Return: void
*/
void free_token(char **tokens)
{
    int i = 0;

    if (!tokens)
        return;
    for (; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}
