#include "ash.h"

/**
  *run_command - execute an inbuilt command
  *
  *@command: command to execute
  *
  *Return: 1 on success
  */
int run_command(char **command)
{
	pid_t child_pid;
	int wstatus;
	char *command_path;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		command_path = find_command_path(command[0]);
		if (!command_path)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}

		if (execve(command_path, command, environ) == -1)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (waitpid(child_pid, &wstatus, 0) == -1)
		{
			perror("Waitpid failed");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
