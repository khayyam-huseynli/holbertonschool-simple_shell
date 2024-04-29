#include "main.h"

/**
 * main - Main function
 *
 * Return: 0 on success
 */

int main(void)
{
	char cmd[MAX_CMD_LEN];
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			printf("$ ");

		if (scanf("%s", cmd) == EOF)
		{
			if (interactive)
				printf("\n");
			exit(EXIT_SUCCESS);
		}

		execute_cmd(cmd);
	}
	return (0);
}
