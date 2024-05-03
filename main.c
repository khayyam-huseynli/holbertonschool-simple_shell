#include "main.h"

/**
 * main - a simple shell that can run commands
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	/**
	char *line = NULL;
	char *name = argv[0];
	size_t len = 0;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);
	int err_stat = 0;
	(void)argc;

	while (1)
	{
		if (interactive)
			printf("Xshell> ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (interactive)
				printf("\n");
			free(line);
			exit(EXIT_SUCCESS);
		}

		err_stat = process_line(line, name);
	}
	free(line);
	return (err_stat);
	**/
	char *input_buffer;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "Xshell> ", 8);
		}
		input_buffer = read_input();
		execute_cmd(input_buffer, argv);
		free(input_buffer);
	}
	return (0);
}
