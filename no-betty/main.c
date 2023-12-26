#include "main.h"

int main(void)
{
    char *command = NULL;
    int status;
    size_t size = SIZE;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");

        if (getline(&command, &size, stdin) == -1)
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        if (command == NULL || command[0] == '\n')
        {
            continue;
        }

        status = execute(command);

        if (status == -1)
        {
            perror("Error: ");
            continue;
        }

        free(command);
    }

    return (0);
}
