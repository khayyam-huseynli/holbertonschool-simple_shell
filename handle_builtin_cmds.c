#include "main.h"

int handle_builtin_commands(char **args, int num_args, char *input)
{
	(void)num_args;

	if (strcmp(args[0], "exit") == 0)
	{
		return (shell_exit(args, input));
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}

