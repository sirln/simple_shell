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
	int l = 0, rd, buffsize = BUFSIZE;
	char c = 0, *buffer, *buf;
	int flag = 0;

	buffer = malloc(buffsize);
	if (!buffer)
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
		if (flag == 0 && c == ' ')
			continue;
		else
			flag = 1;

		buffer[l] = c;
		if (buffer[0] == '\n')
			return (handle_enter(buffer));
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
	buf = handle_space(buffer);
	free(buffer);
	handle_hashtag(buf);
	return (buf);
}


/**
  *handle_enter - handles newline character input
  *
  *@string: String to be handled
  *
  *Return: Empty string
  */
char *handle_enter(char *string)
{
	free(string);
	return ("\0");
}

/**
  *handle_space - remove preceeding whitespaces from input string.
  *
  *@string: Input to be modifies
  *
  *Return: Returns the modified string
  */
char *handle_space(char *string)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(string) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; string[i] == ' '; i++)
		;
	for (; string[i + 1] != '\0'; i++)
	{
		buff[j] = string[i];
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

/**
  *handle_hashtag - removes everything after '#'
  *
  *@buff: input buffer
  */
void handle_hashtag(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}
