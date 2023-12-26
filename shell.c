#include "main.h"

/**
 * main - main function
 * Return: Always 0
 */

int main(void)
{
	int a, b;
	(void)a;
	(void)b;
	if (isatty(STDIN_FILENO))
		a = interactive_mode();
	else
		b = single_line();
	return (0);
}
