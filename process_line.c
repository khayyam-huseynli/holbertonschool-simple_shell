#include "main.h"

/**
 * process_line - tokenizes the line into commands and
 *                executes each one
 * @line: the line to process
 *
 * Return: 0 on success, 1 on failure
 */

int process_line(char *line, char *name)
{
	char *cmds[MAX_CMD_LEN];
	char *argv[MAX_ARGV_LEN];
	char *cmd;
	int num_cmds = 0, i, err_stat = 0;

	/** Tokenize the line into commands and store them in cmds */
	cmd = strtok(line, " \n");
	while (cmd != NULL)
	{
		if (strlen(cmd) > 0 && cmd[0] != ' ')
		{
			cmds[num_cmds] = strdup(cmd);
			num_cmds++;
		}
		cmd = strtok(NULL, " \n");
	}

	 if (num_cmds > 0 && strcmp(cmds[0], "env") == 0)
   	 {
        	print_env();
		for (i = 0; i < num_cmds; i++)
		{
			free (cmds[i]);
		}
		return 0;
	 }
	 if (num_cmds > 0 && strcmp(cmds[0], "exit") == 0)
	 {
		return (shell_exit(cmds, line));
	 }
	
	/** Prepare the arguments for the command */
	for (i = 0; i < num_cmds; i++)
	{
		argv[i] = cmds[i];
	}
	argv[i] = NULL;
	
	/** Execute the command with arguments */
	if (num_cmds > 0)
	{
		err_stat = execute_cmd(cmds[0], argv, name);
	}
	/** Free the allocated memory */
	for (i = 0; i < num_cmds; i++)
	{
		free(cmds[i]);
	}
	return (err_stat);

}
