#include "main.h"

/**
 * execute_cmd - executes a command
 * @cmd: the command to execute
 *
 * Return: 0 on success, 1 on failure
 */

int execute_cmd(char *cmd)
{
	char *argv[2];
	int status;

	argv[0] = cmd;
	argv[1] = NULL;

	if (fork() == 0)
	{
		execve(cmd, argv, NULL);
		perror(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
