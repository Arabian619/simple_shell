#include "hsh.h"

/**
 * prompt - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
**/
void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts("$ ");
}

/**
 * _puts - prints string without a newline
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
	unsigned int len;

	len = _strlen(str);

	write(STDOUT_FILENO, str, len);
}