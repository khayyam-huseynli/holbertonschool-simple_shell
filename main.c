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
	ssize_t n;

	if (isatty(STDIN_FILENO))
		printf("> ");
	while (1)
	{
		n = getline(&cmd, &len, stdin);
		if (n == -1) {
			perror("Error reading line");
			free(cmd);
			exit(1);
		}
		cmd[n - 1] = '\0';  /* Remove newline character */
		if (fork() == 0)
		{
			execute_command(cmd);
			free(cmd);
			exit(0);
		}
		else
			wait(NULL);
		free(cmd);
		cmd = NULL;
		if (isatty(STDIN_FILENO))
			printf("> ");
	}
	if (isatty(STDIN_FILENO))
		printf("\n");
	return (0);
}
