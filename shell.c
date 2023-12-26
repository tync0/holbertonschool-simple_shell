#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - main function
 * Return: Always 0
 */
int main(void)
{
	size_t x = 100;
	char *buf = malloc(x), *cmd;
	char *av[10] = {NULL};
	int ex, i = 0;

	if (!buf)
		exit(98);
	do {
		printf("#cisfun$ ");
		getline(&buf, &x, stdin);
		buf[strcspn(buf, "\n")] = '\0';
		cmd = strtok(buf, " ");
		while (cmd)
		{
			printf("cmd: %s\n", cmd);
			av[i++] = strdup(cmd);
			cmd = strtok(NULL, " ");
		}
		ex = execvp(av[0], av);
		if (ex == -1)
		{
			perror("Error: ");
		}
	} while (1);
	return (0);
}
