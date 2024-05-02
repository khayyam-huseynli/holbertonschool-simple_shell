#include "main.h"

/**
 * execute_cmd - executes a command
 * @cmd: the command to execute
 * @argv: the arguments of command
 * Return: 0 on success, 1 on failure
 */

int execute_cmd(char *cmd, char **argv, char *name)
{
	int status;
	char *fullpath = get_file_path(cmd);

	if (fullpath == NULL || *fullpath == '\0')
	{
		fprintf(stderr, "%s: 1: %s: not found\n", name, cmd);
		return (127);
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
