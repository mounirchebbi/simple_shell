#include "_shell.h"
/**
*_notfound - print not found error
*/
void _notfound(void)
{
	int i = 0;
	char *nf = "command Not Found\n";

	while (nf[i] != '\0')
	{
		_putchar(nf[i]);
		i++;
	}
}
/**
*interactive_mode - shell in interactive mode
*@argc: number of arguments
*@argv: arguments
*/
void interactive_mode(int argc, char **argv)
{
	char *prompt = "$ ";
	char *line;
	char **command;

	if (argv[0] == NULL)
		handle_error();
	else if (argc != 1)
		handle_error();
	while (1)
	{
		_display(prompt);
		line = read_input();
		if (line == NULL)
		handle_error();
		command = malloc(sizeof(char *) * 64);
		if (command == NULL)
		handle_error();
		command = split_line(line, command);
		command = search_path(command);
		if (command)
		{
			execute_command(command);
			free(command);
		}
		else
		_notfound();
	}
}
