#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024

extern char **environ;

/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 *
*/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - link list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
*/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *_getline(FILE *buf);
char **tokenize(char *str);
char *_which(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);

void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

int shell_env(void);
int shell_exit(void);
int builtin_exec(char **tokens);
int num_builtins(built_s builtin[]);

char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);

#endif 
