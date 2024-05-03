#include "main.h"

/**
 * handle_exit - handle exit functionality
 * @input: input value to be handled
 * @status: exit status of the code
 **/
/**
void handle_exit(char *input, int status)
{
	free(input);
	exit(status);
}
**/
/**
 * shell_exit - handle the exit status
 * @args: arguments to be entered
 * @input: checks the status of exit
 *
 * Return: exit status, or 1
 **/

int shell_exit(char **args, char *input)
{
	/**
	 * char *status_str;
	int exit_status;
	int i;

	if (args[1] != NULL)
	{
		exit_status = 0;
		status_str = args[1];

		for (i = 0; status_str[i] != '\0'; i++)
		{
			if (status_str[i] < '0' || status_str[i] > '9')
			{
				handle_exit(input, 2);
				return (1);
			}
			exit_status = exit_status * 10 + (status_str[i]- '0');
		}
		handle_exit(input, exit_status);
	}
	else
	{
		handle_exit(input, 127);
	}
	return (1);
	**/
	if (args[1] != NULL)
	{
		printf("exit: too many arguments\n");
		return (1);
	}
	if (input != NULL && input[0] != '\0')
		    {
			            printf("exit: command not found\n");
				    return (1);
		    }

	free(input);
	exit (2);
}
