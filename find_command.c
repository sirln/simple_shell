#include "ash.h"

/**
  *ash_getenv - gets the value of environment variable by name
  *
  *@env_var_name: Environment variable name
  *
  *Return: The value of the environment variable or NULL if failed
  *
  */
char *ash_getenv(const char *env_var_name)
{
	size_t name_len, env_var_value_len;
	char *env_var_value = NULL;
	int l = 0, n = 0, s = 0;

	name_len = _strlen(env_var_name);
	while (environ[l])
	{
		if (_strncmp(environ[l], env_var_name, name_len) == 0)
		{
			env_var_value_len = _strlen(environ[l]) - name_len;
			env_var_value = malloc(sizeof(char) * (env_var_value_len + 1));
			if (!env_var_value)
			{
				free(env_var_value);
				return (NULL);
			}
			s = name_len + 1;
			while (environ[l][s])
			{
				env_var_value[n] = environ[l][s];
				n++, s++;
			}
			env_var_value[n] = '\0';

			return (env_var_value);
		}
		l++;
	}
	return (NULL);
}


/**
  *generate_command_path - creates command path
  *
  *@path: command location string
  *@command: command whos path we are generating
  *
  *Return: generated path
  *
  */

char *generate_command_path(const char *path, const char *command)
{
	char *command_path;
	size_t len;

	len = _strlen(path) + _strlen(command) + 2;
	command_path = malloc(sizeof(char) * len);
	if (!command_path)
	{
		free(command_path);
		return (NULL);
	}

	_strcpy(command_path, path);
	_strcat(command_path, "/");
	_strcat(command_path, command);

	return (command_path);
}


/**
  *find_command_path - search command in `$PATH` environment variable
  *
  *@command: parsed command string
  *
  *Return: 0 on success or  1 on failure
  *
  */
char *find_command_path(char **command)
{
	struct stat statbuff;
	char *env_var_value, *command_path;
	char *env_path = ash_getenv("PATH");

	env_var_value = _strtok(env_path, ":");
	while (env_var_value)
	{
		command_path = generate_command_path(env_var_value, *command);
		if (stat(command_path, &statbuff) == 0)
		{
			free(env_path);
			printf("%s\n", command_path);
			return (command_path);
		}
		free(command_path);
		env_var_value = _strtok(NULL, ":");
	}
	free(env_path);
	return (NULL);
}
