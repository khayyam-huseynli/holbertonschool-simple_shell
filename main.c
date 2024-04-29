#include "main.h"

/**
 * main - Main function
 *
 * Return: 0 on success
 */

int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			printf("Xshell> ");

		read = getline(&cmd, &len, stdin);
		if (read == -1)
		{
			if (interactive)
				printf("\n");
			free(cmd);
			exit(EXIT_SUCCESS);
		}

		/** Remove trailing newline */
		if (cmd[read - 1] == '\n')
			cmd[read - 1] = '\0';

		execute_cmd(cmd);
	}
	free(cmd);
	return (0);
}
