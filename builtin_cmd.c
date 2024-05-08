#include "main.h"

/**
 * shell_exit - handle the exit status
 * @args: arguments to be entered
 * @input: checks the status of exit
 *
 * Return: exit status, or 1
 **/

void shell_exit(int status)
{

	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(0);
}
