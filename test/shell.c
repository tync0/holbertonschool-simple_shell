#include "main.h"

void tokens(char *command, char **argv)
{
	char *token;
	int len = 0;

	token = strtok(command, " \t\n");
	while (token)
	{
		argv[len++] = token;
		token = strtok(NULL, " \t\n");
	}
}

int shell(void)
{
	char *command, **argv = malloc(100 * sizeof(char *));
	pid_t pid;
	char *test = "alma alma alma armud"
	tokens(test, argv);
	for (int i = 0; argv[i]; i++)
		printf("%s\n", argv[i]);
	return (1);
}

int main(void)
{
	shell();
	return (0);
}
