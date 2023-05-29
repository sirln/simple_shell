#include "ash.h"

/**
  *_strcpy -  function that copies the string pointed to by src,
  *      including the terminating null byte (\0),
  *      to the buffer pointed to by dest.
  *
  *@dest: pointer parameter
  *@src: pointer parameter
  *
  *Return: pointer
  */
char *_strcpy(char *dest, const char *src)
{
	int l = 0;

	while (l <= _strlen(src))
	{
		dest[l] = src[l];
		l++;
	}

	return (dest);
}


/**
 *_strcmp - compares to strings.
 *
 *@s1: string 1
 *@s2: string 2
 *
 *Return: concatenated string
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if  (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}

	return (0);
}



/**
 *_strcat - concatenates two strings.
 *
 *@dest: string to add to
 *@src: string to add
 *
 *Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *new_string = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (new_string);
}


/**
 *_strncmp - compares two strings to a given length/size.
 *
 *@str1: string to compare to
 *@str2: string to compare with
 *@n: size of the second string
 *
 *Return: 0 or the difference
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t l = 0;

	while (l < n && str1[l] && str1[l] == str2[l])
	{
		l++;
	}

	if (l == n)
		return (0);

	return (str1[l] - str2[l]);
}


/**
 *_strdup - returns a pointer to a newly allocated
 *	space in memory, which contains a copy
 *	of the string given as a parameter.
 *
 *@str: parameter
 *Return: NULL or pointer to the array.
 */

char *_strdup(const char *str)
{
	char *l;
	int n = 0;
	int s = 0;

	if (str == NULL)
		return (NULL);

	while (str[n] != '\0')
	{
		n++;
	}

	l = malloc(sizeof(char) * (n + 1));

	if (l == NULL)
		return (NULL);

	while (s < n)
	{
		l[s] = str[s];
		s++;
	}

	return (l);
}
