#include "hsh.h"

/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int stat;
	int execve_stat;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_stat = execve(fullpath, tokens, envp);
		if (execve_stat == -1)
			return (-1);
	}
	else
		wait(&stat);

	return (0);
}
