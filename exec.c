#include "main.h"

void exec(char **args)
{
	char *binaryPath = NULL;
	pid_t pid_child;
	int status;
	
	if (args == NULL)
		exit(99);


	/*generate the path to this command-input before passing it to execve*/
	binaryPath = path_location(args[0]);
	
	pid_child = fork();
	if (pid_child == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid_child == 0)
	{		

		if (execve(binaryPath, args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid_child, &status, 0) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
}
