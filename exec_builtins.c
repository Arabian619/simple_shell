#include "hsh.h"
/**
**builtin_exec - executes builtin functions
**@tokens: arguments being passed
**Return: tokens
**/
int builtin_exec(char **tokens)
{
	int stat;
	unsigned int len;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);

	len = _strlen(tokens[0]);

	num = num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, len) == 0)
		{
			stat = (builtin[i].p)();
			return (stat);
		}
	}
	return (1);
}

/**
**num_builtins - Checks number of built-ins
**@builtin: takes the builtin to be counted
**Return: number of built-ins
**/

int num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (i);
}
