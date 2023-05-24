#include "main.h"

/**
 * path_location - function that finds the path of a given command
 * Return: NULL
**/

char *path_location(char *input)
{
	char *path, *path_copy, *path_token, *file_path;
	int input_length, directory_length;
	struct stat buff;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
	
		input_length = strlen(input);

		path_token = strtok(path_copy, ":");

		while(path_token != NULL)
		{
			directory_length = strlen(path_token);

			file_path = malloc(input_length + directory_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, input);
			strcat(file_path, "\0");

			if (stat(file_path, &buff) == 0)
			{
				free(path_copy);

				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(input, &buff) == 0)
		{
			return (input);
		}
		return (NULL);
	}
	return (NULL);

}
