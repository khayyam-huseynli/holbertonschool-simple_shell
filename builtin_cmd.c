#include "main.h"

/**
 * shell_exit - handle the exit status
 * @args: arguments to be entered
 * @input: checks the status of exit
 *
 * Return: exit status, or 1
 **/

int shell_exit(char **args, char *input)
{
	if (args[1] != NULL)
	{
		printf("exit: too many arguments\n");
		return (1);
	}

	free(input);
	exit(0);
}
