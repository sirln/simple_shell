#include "main.h"

char *path_location(char *input)
{
	char *path, *path_copy, *path_token, *file_path;
	int input_length, directory_length;
	struct stat buff;

	path = getenv("PATH");

	if (path)
	{
		/*creates a copy of the path*/
		path_copy = strdup(path);
	
		/*this gets the length of command the user inputted*/
		input_length = strlen(input);

		/*breaking down the individual paths*/
		path_token = strtok(path_copy, ":");

		while(path_token != NULL)
		{

			/*Allocating memory for a new string that will hold
	 		* the forward slash, the command, null terminating character*/
			directory_length = strlen(path_token);

			file_path = malloc(input_length + directory_length + 2);

			/*copying token obtained in the file_path variable
	 		* appending \, the command and null character as well*/

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
