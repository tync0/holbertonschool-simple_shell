#include "main.h"
/**
 * main - entry point
 * Return: 0 on success, 1 on failure
*/
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
if (command == NULL)
break;
while (command[0] == ' ' || command[0] == '\t')
command++;
if (command[0] == '\n' || command[0] == '\0')
continue;
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
