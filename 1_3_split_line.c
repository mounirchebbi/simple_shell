#include "_shell.h"
/**
 *split_line - split line into arguments
 *@line: line to split_line
 *@command: execute_command
 *Return: command
 */
char **split_line(char *line, char **command)
{
	int i = 0;

	if (line == NULL || line[0] == '\0')
	{
		command = NULL;
		return (command);
	}
	command[i] = strtok(line, " ");
	do {
		i++;
		command[i] = strtok(NULL, " ");
	} while (command[i] != NULL);
	return (command);
}
