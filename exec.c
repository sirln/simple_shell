#include "main.h"

void exec(char **args)
{
	char *binaryPath = NULL;

	if (args)
	{	/*gets the command inputted by user*/
		binaryPath = args[0];
	
		if (execve(binaryPath, args, NULL) == -1)
		{
			perror("Error");
		};
	}
}
