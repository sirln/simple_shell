#include "ash.h"

/**
  *update_lineptr - updates line pointer and its size if necessary
  *
  *@lineptr: pointer to an array of characters
  *@n: pointer to size of array
  *@total_chars: number of characters
  *
  */

void update_lineptr(char **lineptr, size_t *n, ssize_t total_chars)
{
	if (*lineptr == NULL || *n < (size_t)total_chars)
	{
		free(*lineptr);
		*lineptr = (char *)ash_realloc(*lineptr, total_chars);
		if (*lineptr == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		*n = total_chars;
	}
}

/**
  *ash_getline - reads  an entire line from standard input
  *
  *@lineptr: pointer to line buffer
  *@n: pointer to line buffer size
  *@stream: pointer to the standard input stream
  *
  *Return: number of characters read
  *
  */
ssize_t ash_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	ssize_t total_chars = 0;
	ssize_t buffer_size = (ssize_t)sizeof(buffer);
	size_t char_size = sizeof(char);
	char c;


	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while (total_chars < buffer_size - 1 &&  fread(&c, char_size, 1, stream) == 1)
	{
		buffer[total_chars++] = c;
		if (c == '\n')
			break;
	}

	if (total_chars == 0)
		return (-1);

	update_lineptr(lineptr, n, total_chars);

	memcpy(*lineptr, buffer, total_chars);
	(*lineptr)[total_chars - 1] = '\0';

	if (total_chars < buffer_size)
		memmove(buffer, buffer + total_chars, sizeof(buffer) - total_chars);

	return (total_chars);
}
