#include "hsh.h"
/**
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *fullpath, char *path)
{
	unsigned int command_len, path_len, origin_path_len;
	char *path_copy, *token;

	command_len = _strlen(command);
	origin_path_len = _strlen(path);
	path_copy = malloc(sizeof(char) * origin_path_len + 1);
	if (path_copy == NULL)
	{
		perror("Error");
		return (NULL);
	}
	_strcpy(path_copy, path);

	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_len = _strlen(token);
		fullpath = malloc(sizeof(char) * (path_len + command_len) + 2);
		if (fullpath == NULL)
		{
			perror("Error");
			return (NULL);
		}
		_strcpy(fullpath, token);
		fullpath[path_len] = '/';
		_strcpy(fullpath + path_len + 1, command);
		fullpath[path_len + command_len + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (fullpath);
}
