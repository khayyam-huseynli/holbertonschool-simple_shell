#include "main.h"

/**
 * process_line - tokenizes the line into commands and
 *                executes each one
 * @line: the line to process
 *
 * Return: 0 on success, 1 on failure
 */

int process_line(char *line)
{
	char *cmds[MAX_CMD_LEN];
	char *cmd;
	int num_cmds = 0, i;

	/** Tokenize the line into commands and store them in cmds */
	cmd = strtok(line, " \n");
	while (cmd != NULL)
	{
		cmds[num_cmds] = strdup(cmd);
		num_cmds++;
		cmd = strtok(NULL, " \n");
	}

	if (num_cmds > 0 && strcmp(cmds[0], "env") == 0)
	{
       		print_environment(envp);
        }
        return 1;  
    }
	/** Execute each command */
	for (i = 0; i < num_cmds; i++)
	{
		execute_cmd(cmds[i]);
		free(cmds[i]);
	}
	
	return (0);
}
