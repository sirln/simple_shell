#include "main.h"

/*it returns a pointer to the newly allocated memory block*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_mem;
	char *ptr_copy, *filler;
	unsigned int i;
	
	/*function returns original pointer as there's no need to re-size memory*/
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
	/*the new_mem is stored in the char variable filler*/
	filler = new_mem;

	/*the function copies the contents of old memory to the new memory*/
	for (i = 0; i < old_size && i < new_size; i++)
		filler[i] = *ptr_copy++;

	free(ptr);
	return (new_mem);
}


/*a helper function that is used to assign a pointer to lineptr to a bew buffer*/
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t p)
{	
	if (*lineptr == NULL)
	{	/*n is size of lineptr and p is the size of the buffer*/
		if (p > 200)
			*n = p;
		else
			*n = 200;
		*lineptr = buffer;
	}
	/*else if (*n < p)
	{
		if (p > 200)
			*n = p;
		else
			*n = 200;
		*lineptr = buffer;
	}*/
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/*This function reads the input and returns the no. of bytes read*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input; /*variable used to keep track of the no. of characters read so far*/
	ssize_t np; /*stores the no. of characters read*/
	char s = 'x', *buffer; /*s stores the current character read & buffer stores the line*/
	int p;

	if (input == 0)
		fflush(stream); /*to ensure any buffered data is written to the file*/
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 200);
	if (buffer == NULL)
		return (-1);

	while (s != '\n') /*reads characters from the file stream until newline character*/
	{
		p = read(STDIN_FILENO, &s, 1);
		if (p == -1 || (p == 0 && input == 0))
		{	/*if the EOF and no characters read/error occured, the function frees the buffer*/
			free(buffer);
			return (-1);
		}
		if (p == 0 && input != 0)
		{
			input++;
			break;
		}
		
		/*the function re-allocates memory for the buffer variable*/
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
