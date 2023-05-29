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
	/*char *command_path;*/

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(*command, command, environ) == -1)
			return (2);
		return (0);
	}
	else
	{
		if (waitpid(child_pid, &wstatus, 0) == -1)
		{
			perror("Waitpid failed");
			return (WEXITSTATUS(wstatus));
		}
	}

	return (WEXITSTATUS(wstatus));
}
