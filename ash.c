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
		prompt();
	}
}

/**
  *ash - ash shell program
  *
  *Return: program status
  */

int ash(void)
{
	int status = 1;
	char **cmd, **commands, *input;

	signal(SIGINT, signal_handler);
	while (status)
	{
		prompt();

		input = get_command();
		if (!input || input[0] == '\n')
		{
			free(input);
			break;
		}
		commands = separate_commands(input);
		cmd = parse_command(*commands);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			free(cmd);
			free(commands);
			free(input);
			exit(98);
		}

		status = run_command(cmd);
		free(cmd);
		free(commands);
		free(input);
	}
	return (status);
}
