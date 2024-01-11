#include "hsh.h"

/**
 * _getline - puts input from user into buffer
 * @buf: buffer for user input
 * Return: buffer of user input
 */
char *_getline(FILE *buf)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, buf);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
