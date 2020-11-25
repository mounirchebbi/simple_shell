#include "_shell.h"
/**
 *execute_command - executes the command
 *@command: command to executes
 *Return: int
 */
int execute_command(char **command)
{
	pid_t child_pid;
	int status, r;

	if (command == NULL)
		return (-1);
	child_pid = fork();
	if (child_pid == -1)
		return (-1);
	else if (child_pid == 0)
	{
		r = execve(command[0], command, environ);
		if (r != 0)
		{
			return (-1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	return (0);
}
