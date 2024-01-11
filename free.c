#include "hsh.h"

/**
 * free_all - frees all malloc'd space at end of main loop
 * @tokens: pointer to tokens array
 * @path: pointer to path variable
 * @line: pointer to user input buffer
 * @fullpath: pointer to full path
 * @flag: flag marking if fullpath was malloc'd
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - free double pointer
 * @arr: double pointer to free
 * @len: length of double pointer
 */
void free_dp(char **arr, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
