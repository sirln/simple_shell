#include "ash.h"

/**
  *parse_command - parse command given from stdin
  *
  *@input: input from stdin
  *
  *Return: parsed strings to be used as arguments
  */

char **parse_command(char *input)
{
	char **commands;
	char *command;
	int i_arg = 0;
	size_t input_len;
	size_t buffsize = 1024;
	char *delimiters = "\n\t\r\a ";

	input_len = _strlen(input);
	if (input[0] == ' ' && input[input_len] == ' ')
		exit(0);
	if (!input)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		return (NULL);
	}
	command = _strtok(input, delimiters);
	while (command)
	{
		commands[i_arg] = command;
		i_arg++;
		command = _strtok(NULL, delimiters);
	}
	commands[i_arg] = NULL;

	return (commands);
}



/**
  *separate_command - separate command given from stdin
  *
  *@input: input from stdin
  *
  *Return: parsed strings to be used as commands
  */

char **separate_command(char *input)
{
	char **commands;
	char *command;
	int i_arg = 0;
	size_t input_len;
	size_t buffsize = 1024;
	char *delimiters = "&;";

	input_len = _strlen(input);
	if (input[0] == ' ' && input[input_len] == ' ')
		exit(0);
	if (!input)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		return (NULL);
	}
	command = _strtok(input, delimiters);
	while (command)
	{
		commands[i_arg] = command;
		i_arg++;
		command = _strtok(NULL, delimiters);
	}
	commands[i_arg] = NULL;

	return (commands);
}
