#include "main.h"

/**
 * execute_cmd - executes a command
 * @cmd: the command to execute
 * @argv: the arguments of command
 * Return: 0 on success, 1 on failure
 */

int execute_cmd(char *cmd, char **argv)
{
	int status;
	char *fullpath = get_file_path(cmd);

	if (fullpath == NULL)
	{
		fprintf(stderr, "%s: command not found\n", cmd);
		return (-1);
	}

	if (fork() == 0)
	{
		execve(fullpath, argv, NULL);
		perror(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	free(fullpath);
	return (0);
}
