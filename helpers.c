#include "main.h"

/**
 * execute - function that executes a command
 * @argv: array of tokens
 * @pid: process id
 * Return: 1 on success, -1 on failure
 */
int execute(char **argv, pid_t pid)
{
if (pid == -1)
perror("Error: ");
if (pid == 0)
{
if (execve(argv[0], argv, NULL) == -1)
{
perror("Error: ");
return (0);
}
}
else if (pid == -1)
{
perror("fork");
return (0);
}
else
{
int status;
pid_t waitstatus;
waitstatus = waitpid(pid, &status, 0);
if (waitstatus == 0)
	perror("wait pid");
}
return (1);
}


/**
 * tokens - function that tokenizes a string
 * @command: string to be tokenized
 * @argv: array of tokens
 * Return: void
*/
void tokens(char *command, char **argv)
{
int i = 0;
char *token;

token = strtok(command, " \t\n");
while (token != NULL)
{
argv[i] = token;
token = strtok(NULL, " \t\n");
i++;
}
argv[i] = NULL;
}

int c_trim(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
    str1[k] = '\0';
    return strlen(str1);
}
