#include "main.h"

/**
  *display_prompt - prompt
  */

void display_prompt(void)
{
	write(1, "$ ", 2);
}


/**
  *execute_command - prompt
  *@command: command
  */
void execute_command(char *command)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execlp(command, command, NULL) == -1)
	{
		perror("execlp failed");
		exit(EXIT_FAILURE);
	}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}


/**
  *main - start
  *Return: 0 on success
  */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			write(1, "\n", 1);
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}

	return (0);
}
