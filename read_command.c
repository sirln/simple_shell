#include "ash.h"

/**
  *prompt - write a prompt to screen/ standard output
  */

void prompt(void)
{
	char *prompt = "(ASh)~> ";
	size_t len_prompt = _strlen(prompt);

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, prompt, len_prompt);

}

/**
  *get_command - reads input from keyboard/standard input
  *
  *Return: input string
  */


char *get_command(void)
{
	char *line = NULL;
	ssize_t chars;
	size_t len_line = 0;

	chars = ash_getline(&line, &len_line, stdin);
	if (chars == -1)
	{
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';

	return (line);
}



