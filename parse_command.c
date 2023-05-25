#include "ash.h"

/**
  *parse_command - breaks down a command string
  *
  *@command: string to break down
  *@args: array to store vroken down strings
  */
void parse_command(char *command, char **args)
{
	char *token;
	char *delimiters = " \t\n";
	int i_arg = 0;

	token = _strtok(command, delimiters);
	while (token)
	{
		args[i_arg] = token;
		i_arg++;
		token = _strtok(NULL, delimiters);
	}
	args[i_arg] = NULL;
}
