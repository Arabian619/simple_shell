#include "hsh.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @var: variable to compare against
 * @len: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *var, unsigned int len)
{
	unsigned int var_len;
	unsigned int i;

	var_len = _strlen(var);
	if (var_len != len)
		return (-1);

	i = 0;
	while (name[i] != '\0' && var[i] != '\0')
	{
		if (name[i] != var[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * up to given length are the same
 * @name: name supplied by user to search for
 * @var: variable to compare against
 * @len: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *var, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		if (name[i] != var[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @str: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *str)
{
	int i;
	int j = _strlen(str);

	for (i = 0; i <= j; i++)
		dest[i] = str[i];

	return (dest);
}
/**
 * _strlen - returns the length of a string
 * @str: string to be evaluated
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
