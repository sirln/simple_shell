#include "ash.h"

/**
 * compare_delim- compares if a character matches any char str
 * @p: character to check
 * @str: string to check
 * Return: 1 (on success) else 0 if fails
**/

unsigned int compare_delim(char p, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (p == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that tokenises a string
 * @str: string
 * @delim: delimiter
 * Return: a pointer to the current position in the string
**/

char *_strtok(char *str, const char *delim)
{
	static char *current, *new_token;
	unsigned int k;

	if (str != NULL)
		new_token = str;
	current = new_token;
	if (current == NULL)
		return (NULL);
	for (k = 0; current[k] != '\0'; k++)
	{
		if (compare_delim(current[k], delim) == 0)
			break;
	}
	if (new_token[k] == '\0')
	{
		new_token = NULL;
		return (NULL);
	}
	current = new_token + k;
	new_token = current;
	for (k = 0; new_token[k] != '\0'; k++)
	{
		if (compare_delim(new_token[k], delim) == 1)
			break;
	}
	if (new_token[k] == '\0')
		new_token = NULL;
	else
	{
		new_token[k] = '\0';
		new_token = new_token + k + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (current);
}
