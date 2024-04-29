#include "main.h"

/**
 * execute_command - Executes a command
 * @cmd: The command to execute
 */
void execute_command(char *cmd)
{
	char *args[MAX_ARGS];
	char *token;
	int i = 0;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (execve(args[0], args, environ) == -1)
	{
		perror("Error executing command");
	}
}
