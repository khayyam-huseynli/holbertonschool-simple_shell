#include "main.h"

/**
 * main - a simple shell that can run commands
 *
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);

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

		if (strcmp(line, "env\n") == 0)
		{
            		print_environment();
        	}
		process_line(line);
	}
	free(line);
	return (0);
}
