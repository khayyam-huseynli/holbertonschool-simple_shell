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
	while ((n = getline(&cmd, &len, stdin)) != -1)
	{
		cmd[n - 1] = '\0';  /* Remove newline character */
		/* Handle 'exit' command */
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(0);
		}
		/* Ignore special characters */
		if (cmd[0] == '^')
		{
			free(cmd);
			continue;
		}
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
