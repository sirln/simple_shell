#include "ash.h"

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
		if (strncmp(environ[l], "PATH=", 5) == 0)
		{
			pathVariable = environ[l] + 5;
			path = strtok(pathVariable, ":");

			while (path)
			{
				command_path = (char *)malloc(strlen(path) + strlen(command) + 2);
				if (!command_path)
				{
					perror("malloc error");
					exit(EXIT_FAILURE);
				}
				strcpy(command_path, path);
				strcat(command_path, "/");
				strcat(command_path, command);
				strcat(command_path, "\0");

				if (access(command_path, F_OK) == 0)
					return (command_path);

				path = strtok(NULL, ":");
				free(command_path);
			}
			if (stat(command, &statbuff) == -1)
			{
				perror("File not found");
				exit(EXIT_FAILURE);
			}
			else
			{
				return (command);
			}
		}
		l++;
	}
	perror("PATH variable not found");
	exit(EXIT_FAILURE);
}
