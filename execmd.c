#include "main.h"

/**
 * execute_cmd - executes a command
 * @cmd: the command to execute
 * @argv: the arguments of command
 * Return: 0 on success, 1 on failure
 */
void execute_cmd(char *cmd, char *argv[])
{
	int status, num_args;
	char *args[10];
	pid_t child_pid;
	char *shell_name, *path;

	shell_name = argv[0];
	num_args = process_line(cmd, args);


	if (num_args == 0)
		return;
	if (handle_builtin_commands(args, num_args, cmd) == 1)
		return;
	path = get_file_path(args[0]);
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: failed to create");
		free(cmd);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			write(2, shell_name, strlen(shell_name));
			write(2, ": 1: ", 5);
			write(2, args[0], strlen(args[0]));
			write(2, ": not found\n", 12);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
}



	/**
	
	if (fullpath == NULL || *fullpath == '\0')
	{
		fprintf(stderr, "%s: 1: %s: not found\n", name, cmd);
		free(fullpath);
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
	**/
