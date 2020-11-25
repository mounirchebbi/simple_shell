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
void handle_error(void);
#endif
