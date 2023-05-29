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
	int l = 0, rd, buffsize = 1024;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (c != EOF && c != '\n')
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (!rd)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[l] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (l >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		l++;
	}
	buffer[l] = '\0';
	buf = space(buffer);
	free(buffer);
	return (buf);
}


/**
  * enter - Handles newline character input
  *
  * @string: String to be handled
  *
  *Return: Empty string
  */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
  * space - Modifies the input string to remove preceeding whitespaces
  *
  * @str: Input to be modifies
  *
  * Return: Returns the modified string
  */
char *space(char *str)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buff[j] = str[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
