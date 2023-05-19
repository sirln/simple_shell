#include "main.h"

void exec(char **args)
{
	char *binaryPath = NULL;

	if (args)
	{	

		/*generate the path to this command-input before passing it to execve*/
		binaryPath = path_location(args[0]);

		if (execve(binaryPath, args, NULL) == -1)
		{
			perror("Error");
		}
	}
}
