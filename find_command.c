#include "ash.h"

/**
  *generate_command_path - creates command path
  *
  *@path: command location string
  *@command: command whos path we are generating
  *
  *Return: generated path
  *
  */

char *generate_command_path(const char *path, const char *command)
{
	char *command_path;

	command_path = (char *)malloc(_strlen(path) + _strlen(command) + 2);
	if (!command_path)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	_strcpy(command_path, path);
	_strcat(command_path, "/");
	_strcat(command_path, command);
	return (command_path);
}


/**
  *find_command_path - functions to get command path
  *
  *@command: command string
  *
  *Return: command path if exists otherwise NULL
  *
  */
char *find_command_path(char *command)
{
	int l = 0;
	char *pathVariable, *path, *command_path;
	struct stat statbuff;

	while (environ[l])
	{
		if (_strncmp(environ[l], "PATH=", 5) == 0)
		{
			pathVariable = environ[l] + 5;
			path = _strtok(pathVariable, ":");

			while (path)
			{
				command_path = generate_command_path(path, command);

				if (access(command_path, F_OK) == 0)
					return (command_path);

				path = _strtok(NULL, ":");
				free(command_path);
			}
			if (stat(command, &statbuff) == -1)
			{
				perror("File not found");
				exit(EXIT_FAILURE);
			}
			else
				return (_strdup(command));
		}
		l++;
	}
	perror("PATH variable not found");
	exit(EXIT_FAILURE);
}
