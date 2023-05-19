#include "ash.h"

/**
  *
  */
void parse_command(char *command, char **args)
{
	char *token;
	char *delimiters = " \t\n";
	int i_arg = 0;

	token = strtok(command, delimiters);
	while (token)
	{
		args[i_arg] = token;
		i_arg++;
		token = strtok(NULL, delimiters);
	}
	args[i_arg] = NULL;
}
