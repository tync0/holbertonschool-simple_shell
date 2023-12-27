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
 * execute - executes a command
 * @pid: pid of the process
 * @command: command to execute
 * Return: void
 */
void execute(pid_t pid, char *command)
{
    int status;

    if (pid == -1)
    {
        free(command);
        perror("Error");
    }
    else if (pid == 0)
    {
        execute_command(command);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}

/**
 * execute_command - executes a command
 * @command: command to execute
 * Return: returns 0 on success
 */
int execute_command(char *command)
{
    char **arr;

    arr = split(command);
    if (arr == NULL)
    {
        perror("Error");
        exit(1);
    }

    if (execve(command, arr, environ) == -1)
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
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}