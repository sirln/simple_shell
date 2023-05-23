#include "main.h"

int main(int ap, char **args)
{
	char *prompt = "(ASh)$ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t k = 0;
	ssize_t chars_read;
	const char *delim = " \n";
	int no_of_strings = 0;
	char *word;
	int p;

	/*declaring unused variables as void for now*/
	(void)ap;

	/*the infinite loop helps to print the prompt continously*/
	while (1)
	{
	write(1, prompt, strlen(prompt));

	chars_read = _getline(&lineptr, &k, stdin);
	if (chars_read == -1)
	{
		return (-1);
	}

	/*I'm allocating space for the copy of the lineptr*/
	lineptr_copy = malloc(sizeof(char) * chars_read);

	if (lineptr_copy == NULL)
	{
		perror("Failure allocating memory");
		return (-1);
	}

	/*copying lineptr to lineptr_copy*/
	strcpy(lineptr_copy, lineptr);

	/*Process of tokenisation: breaking the string to an array of words
	 * counting the no. of tokens expected from the string*/

	word = strtok(lineptr, delim);

	while (word != NULL)
	{
		no_of_strings++;
		word = strtok(NULL, delim);
	}
	no_of_strings++;

	/*allocating space to store the no. of strings in args*/

	args = malloc(sizeof(char) * no_of_strings);

	/*storing each string(word) in the args array*/

	word = strtok(lineptr_copy, delim);

	for (p = 0; word != NULL; p++)
	{
		args[p] = malloc(sizeof(char) * strlen(word));
		strcpy(args[p], word);

		word = strtok(NULL, delim);
	}
	args[p] = NULL;

	/*executing the exec command*/

	exec(args);

	free(args);
	/*free(lineptr);*/
	free(lineptr_copy);
	}

	return (0);
}
