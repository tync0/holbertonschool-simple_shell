#include "main.h"

/**
 * main - main function of the shell
 * Return: returns 0 on success
 */
int main(void)
{
    char *command = NULL;
    int read;
    pid_t pid;
    size_t size;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");
        fflush(stdout);
        read = getline(&command, &size, stdin);
        if (read == -1)
        {
            break;
        }
        command[read - 1] = '\0';
        if (command == NULL)
            exit(0);

        while (command[0] == ' ' || command[0] == '\t')
            command++;

        if (command[0] == '\n' || command[0] == '\0')
            continue;

        if (strcmp(command, "exit") == 0)
            exit(0);

        pid = fork();
        execute(pid, command);
    }
    return (0);
}
