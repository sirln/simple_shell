#include "ash.h"

/**
  *prompt - write a prompt to screen/ standard output
  */

void prompt(void)
{
	char *prompt = "$ ";
	size_t len_prompt = _strlen(prompt);

	write(STDOUT_FILENO, prompt, len_prompt);

}

/**
  *get_command - reads input from keyboard/standard input
  *
  *Return: input string
  */
char *get_command(void)
{
	char *command = NULL;
	ssize_t read;
	size_t len_command = 0;

	read = ash_getline(&command, &len_command, stdin);
	if (read == -1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}

	return (command);
}


