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

	if (child_pid == 0)
	{
		command_path = find_command_path(command[0]);
		if (!command_path)
		{
			free(command_path);
			exit(2);
		}

		if (execve(command_path, command, environ) == -1)
		{
			return (2);
		}
		else
			return (0);
	}
	else
	{
		if (waitpid(child_pid, &wstatus, 0) == -1)
			return (WEXITSTATUS(wstatus));
	}
	return (WEXITSTATUS(wstatus));
}
