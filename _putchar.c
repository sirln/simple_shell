#include "ash.h"

/**
  * _putchar - writes character to standard output
  *@c : character to print
  *
  * Return:  1
  *
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
  *_strlen - function that returns the length of a string.
  *
  *@s: pointer parameter
  *
  *Return: returns l.
  */
int _strlen(const char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
	{
		continue;
	}

	return (l);
}
