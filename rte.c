#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	char *buf = malloc(100);
	size_t x = 100;
	char *av[2];
	int ex;

	if (!buf)
		exit(98);
	do {
		printf("#cisfun$ ");
		getline(&buf, &x, stdin);
		buf[strcspn(buf, "\n")] = '\0';
		av[0] = strdup(buf);
		av[1] = NULL;
		ex = execvp(av[0], av);
		if (ex == -1)
		{
			sprintf(buf, "%s: ", argv[0]);
			perror(buf);
		}
	} while (1);
	return (0);
}
