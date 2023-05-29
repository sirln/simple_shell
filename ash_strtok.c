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
	static char *current, *new;
	unsigned int k;

	if (str != NULL)
		new = str;
	current = new;
	if (current == NULL)
		return (NULL);
	for (k = 0; current[k] != '\0'; k++)
	{
		if (compare_delim(current[k], delim) == 0)
			break;
	}
	if (new[k] == '\0')
	{
		new = NULL;
		return (NULL);
	}
	current = new + k;
	new = current;
	for (k = 0; new[k] != '\0'; k++)
	{
		if (compare_delim(new[k], delim) == 1)
			break;
	}
	if (new[k] == '\0')
		new = NULL;
	else
	{
		new[k] = '\0';
		new = new + k + 1;
		if (*new == '\0')
			new = NULL;
	}
	return (current);
}
