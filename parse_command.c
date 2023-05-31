#include "ash.h"

/**
  * parse_command - Parses the command recieved from stdin
  *
  * @input: String gathered from stdin
  *
  * Return: Parsed strings to be used as arguments
  */
char **parse_command(char *input)
{
	char *delimiters = "\n\t\r\a ";
	char **arguments;
	char *argument;
	int i = 0;
	int buffsize = BUFSIZE;
	int input_len = _strlen(input);

	if (input == NULL)
		return (NULL);
	if (input[0] == ' ' && input[input_len] == ' ')
		exit(0);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(input, delimiters);
	for (; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, delimiters);
	}
	arguments[i] = NULL;

	return (arguments);
}



/**
  * separate_commands - separate command recieved from stdin
  *
  * @input: String gathered from stdin
  *
  * Return: Parsed strings to be used as commands
  */
char **separate_commands(char *input)
{
	char *delimiters = ";&";
	char **arguments;
	char *argument;
	int i = 0;
	int buffsize = BUFSIZE;
	int input_len = _strlen(input);

	if (input == NULL)
		return (NULL);
	if (input[0] == ' ' && input[input_len] == ' ')
		exit(0);

	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(input, delimiters);
	for (; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, delimiters);
	}
	arguments[i] = NULL;

	return (arguments);
}
