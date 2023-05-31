#include "ash.h"

/**
 * ash_env - Prints the current environment of the shell
 * @args: no. of arguements passed to the shell
 * @status: exit status of last command
 * Return: -1 if an error occurs, otherwise 0
**/

int ash_env(char **args, int status)
{
	int p;
	char np = '\n';
	int len;

	if (!environ)
		return (-1);

	for (p = 0; environ[p]; p++)
	{
		len = _strlen(environ[p]);
		write(STDOUT_FILENO, environ[p], len);
		write(STDOUT_FILENO, &np, 1);
	}
	(void)args;
	(void)status;

	return (0);
}

/**
 * check_builtin - matches a command with its corresponding ash builtin
 * @command: The command that needs to be matched
 * Return: 0 on success else -1 if it fails
**/

int check_builtin(char **command)
{
	builtin_d built_functs[] = {
		{ "env", NULL },
		{ NULL, NULL }
	};
	int k;

	if (!command)
		return (-1);

	for (k = 0; built_functs[k].name; k++)
	{
		if (_strcmp(built_functs[k].name, command[0]) == 0)
			return (0);
	}
	return (-1);
}


/**
 * convert_builtin - matches a command with its corresponding ash builtin
 * @command: The command that needs to be matched
 * @status: exit status
 * Return: A function ptr to the corresponding builtin
**/

int convert_builtin(char **command, int status)
{
		builtin_d built_functs[] = {
		{ "env", ash_env },
		{ NULL, NULL }
	};
	int k;

	if (!command)
		return (-1);

	for (k = 0; built_functs[k].name; k++)
	{
		if (_strcmp(built_functs[k].name, command[0]) == 0)
			return (built_functs[k].function(command, status));
	}
	return (-1);
}
