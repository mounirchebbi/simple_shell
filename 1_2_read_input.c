#include "_shell.h"
/**
 *read_input - reads input from stdin
 *Return: line
 */
char *read_input()
{
	int i = 0;
	char *line = NULL;
	size_t buffer = 0;

	if (getline(&line, &buffer, stdin) == EOF)
	{
		_putchar('\n');
		exit(0);
	}
	else
	{
		while (line[i] != '\n')
			++i;
		line[i] = '\0';
		return (line);
	}
}
