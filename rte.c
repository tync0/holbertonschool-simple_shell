#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	char *buf = malloc(100);
	size_t x = 100;
	char *av[2];

	if (!buf)
		exit(98);
	getline(&buf, &x, stdin);
	buf[strcspn(buf, "\n")] = '\0';
	av[0] = strdup(buf);
	av[1] = NULL;
	if (execvp(av[0], av) == -1)
	{
		perror("Error: ");
	}
	return (0);
}
