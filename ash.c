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
	int status = 1, stat = 0;
	char **cmd, **commands, *input;

	signal(SIGINT, signal_handler);
	while (status)
	{
		prompt();

		input = get_command();
		if (!input)
		{
			free(input);
			break;
		}
		if (input[0] == '\0')
			continue;

		commands = separate_commands(input);
		cmd = parse_command(*commands);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			free(cmd);
			free(commands);
			free(input);
			exit(stat);
		}
		else if (check_builtin(cmd) == 0)
		{
			stat = convert_builtin(cmd, stat);
			free(cmd);
			continue;
		}
		else
			stat = run_command(cmd);
		free(cmd);
		free(commands);
		free(input);
		wait(&stat);
	}
	return (status);
}
