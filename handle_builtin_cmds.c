#include "main.h"

/**
* handle_builtin_commands - handel builtin commands
* @args: list of arguments
* @status: status code
* Return: returns 0 on success 1 else
*/

int handle_builtin_commands(char **args, int status)
{

	if (strcmp(args[0], "exit") == 0)
	{
		shell_exit(status);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}

