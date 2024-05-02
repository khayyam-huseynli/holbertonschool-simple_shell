#include "main.h"

/**
 * main - a simple shell that can run commands
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	char *name = argv[0];
	size_t len = 0;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);
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

		process_line(line, name);
	}
	free(line);
	return (0);
}
