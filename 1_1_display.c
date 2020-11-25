#include "_shell.h"
/**
*_display - displays prompt
*@prompt: prompt
*Return: int
*/
int _display(char *prompt)
{
	int i = 0;

	while (prompt[i] != '\0')
	{
		_putchar(prompt[i]);
		i++;
	}
	return (i);
}
