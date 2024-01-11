#include "hsh.h"
/**
 * main - simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
	int flag, builtin_stat, child_stat;
	struct stat buf;

	while (1)
	{
		prompt(STDIN_FILENO, buf);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = tokenize(line);
		if (tokens[0] == NULL)
			continue;
		builtin_stat = builtin_exec(tokens);
		if (builtin_stat == 0 || builtin_stat == -1)
		{
			free(tokens);
			free(line);
		}
		if (builtin_stat == 0)
			continue;
		if (builtin_stat == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		path = _getenv("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1;
		child_stat = child(fullpath, tokens);
		if (child_stat == -1)
			perror("Error");
		free_all(tokens, path, line, fullpath, flag);
	}
	return (0);
}
