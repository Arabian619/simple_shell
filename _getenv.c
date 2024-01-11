#include "hsh.h"
/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	char **env_copy;
	char *var, *value, *path;
	int cmp;
	unsigned int path_len, env_len, len, i;

	env_len = 0;
	while (environ[env_len] != NULL)
		env_len++;
	env_copy = NULL;
	env_copy = copy_env(env_copy, env_len);

	len = _strlen((char *)name);
	i = 0;
	while (env_copy[i] != NULL)
	{
		var = env_copy[i];
		cmp = _strncmp((char *)name, var, len);
		if (cmp == 1)
		{
			value = strtok(var, "=");
			value = strtok(NULL, "\n ");
			if (value == NULL)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			path_len = _strlen(value);
			path = malloc(sizeof(char) * path_len + 1);
			if (path == NULL)
			{
				perror("Error");
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(env_copy, env_len);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * copy_env - copies environment variable
 * @env_copy: pointer to copy of environment variable
 * @env_len: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **copy_env(char **env_copy, unsigned int env_len)
{
	char *var;
	unsigned int var_len;
	unsigned int i;

	env_copy = malloc(sizeof(char **) * (env_len));
	if (env_copy == NULL)
	{
		perror("Error");
		return (NULL);
	}

	i = 0;
	while (i < env_len)
	{
		var = environ[i];
		var_len = _strlen(var);

		env_copy[i] = malloc(sizeof(char) * var_len + 1);
		if (env_copy[i] == NULL)
		{
			perror("Error:");
			return (NULL);
		}
		_strcpy(env_copy[i], environ[i]);
		i++;
	}

	return (env_copy);
}
