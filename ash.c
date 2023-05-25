#include "ash.h"


/**
 * signal_handler - checks if Ctrl C is pressed
 * @sig_num: integer
 */
void signal_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_putchar('\n');
		exit(0);
	}
}

/**
  *ash - get input/command
  *
  *@command: command to be run
  */

void ash(char **command)
{
	int status = 1;
	char *cmd = NULL, **args = NULL;

	(void)command;
	while (status)
	{
		signal(SIGINT, SIG_DFL);
		prompt();

		cmd = get_command();
		if (cmd == NULL || cmd[0] == '\n')
		{
			free(cmd);
			continue;
		}
		args = malloc(sizeof(char *) * 256);
		if (args == NULL)
		{
			perror("Memory allocation failed");
			free(cmd);
			exit(EXIT_FAILURE);
		}

		parse_command(cmd, args);
		if (args == NULL)
		{
			free(cmd);
			free(args);
			continue;
		}

		if (_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			free(args);
			exit(98);
		}

		status = run_command(args);

		free_args(args);
	}
}

/**
  *free_args - frees memory
  *
  *@args: variable to deallocate memory
  *
  */
void free_args(char **args)
{
	int l = 0;

	if (args == NULL)
		return;

	while (args[l] != NULL)
	{
		free(args[l]);
		l++;
	}

	free(args);
}
