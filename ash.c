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
		exit(200);
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
	char *cmd, *args[256];

	(void)command;
	while (status)
	{
		signal(SIGINT, signal_handler);
		prompt();

		cmd = get_command();
		if (cmd[0] == '\n')
		{
			free(cmd);
			continue;
		}
		parse_command(cmd, args);
		if (_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(98);
		}
		status = run_command(args);
		free(cmd);
	}
}
