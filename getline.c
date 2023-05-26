#include "main.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t p);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - function that reallocates memory
 * @ptr: A pointer to the memory that was allocated previously
 * @old_size: The size in bytes for the space allocated for the ptr
 * @new_size: The size in bytes for the new memory block created
 * Return: if new_size == old_size - ptr
 * if new_size == 0 & ptr is not NULL - NULL
 * otherwise a ptr to the reallocated memory block
**/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_mem;
	char *ptr_copy, *filler;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_mem = malloc(new_size);
		if (new_mem == NULL)
			return (NULL);

		return (new_mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	new_mem = malloc(sizeof(*ptr_copy) * new_size);
	if (new_mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	filler = new_mem;

	for (i = 0; i < old_size && i < new_size; i++)
		filler[i] = *ptr_copy++;

	free(ptr);
	return (new_mem);
}


/**
 * assign_lineptr - reassigns the lineptr variable for _getline
 * @lineptr: parameter
 * @n: size of linptr
 * @buffer: string to assign to the lineptr
 * @p: The size of the buffer
**/
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t p)
{
	if (*lineptr == NULL)
	{
		if (p > 200)
			*n = p;
		else
			*n = 200;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - function that reads the input from a stream
 * @lineptr: the buffer that stores the input
 * @n: The size of the lineptr
 * @stream: The stream to read the input from
 * Return: The total number of bytes read
**/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t np;
	char s = 'x', *buffer;
	int p;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 200);
	if (buffer == NULL)
		return (-1);

	while (s != '\n')
	{
		p = read(STDIN_FILENO, &s, 1);
		if (p == -1 || (p == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (p == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 200)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = s;
		input++;
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	np = input;
	if (p != 0)
		input = 0;
	return (np);
}
