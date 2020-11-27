#ifndef _SHELL_HEADER
#define _SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024
extern char **environ;
void interactive_mode(int argc, char **argv);
int _display(char *prompt);
char *read_input();
char **split_line(char *line, char **command);
char **search_path(char **command);
int execute_command(char **command);
int _putchar(char c);
int _strlen(char *str);
char *_strcpy(char *out, char *in);
char *_strcat(char *a, char *b, char *c);
int _strcmp(char *name, char *variable, unsigned int length);
void handle_error(void);


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);



/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 *
 * Description: generic linked list struct for variables.
**/

typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/

typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);
int shell_env(void);
char **tokenizer(char *str);


#endif
