#include "ash.h"

/**
  *run_command - execute an inbuilt command
  *
  *@command: command to execute
  */
int run_command(char **command)
{
	pid_t child_pid;
	int wstatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (child_pid == 0)
	{
		execve(command[0], command, environ);
		_exit(1);
	}
	else
	{
		if (waitpid(child_pid, &wstatus, 0) == -1)
			return (-1);
		return (wstatus);
	}
}
