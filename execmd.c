#include "main.h"

/**
 * execute_command - Executes a command
 * @cmd: The command to execute
 */

void execute_command(char *cmd)
{
	char **args;
	char *token;
	int i = 0, num_tokens = 0;

	/* First, count the number of tokens in the command */
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, " ");
	}

	/* Allocate memory for args based on the number of tokens */
	args = malloc(sizeof(char *) * (num_tokens + 1));
	if (args == NULL)
	{
		perror("Error allocating memory");
		exit(1);
	}

	/* Tokenize the command again and fill the args array */
	i = 0;
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

	/* Free the allocated memory */
	free(args);
}
