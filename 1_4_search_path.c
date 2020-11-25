#include "_shell.h"
/**
 *extract_paths - extracts the path string from environ
 *@paths: paths
 *@n: line of paths in environ
 *Return: paths
 */
char **extract_paths(char **paths, int n)
{
	int i = 0;
	char *temp;
	char *arg;
	char *env = malloc(sizeof(char) * _strlen(environ[n]) + 1);

	env = _strcpy(env, environ[n]);
	strtok(env, "=");
	temp = strtok(NULL, "=");
	paths[0] = strtok(temp, ":");
	do {
		i++;
		arg = strtok(NULL, ":");
		paths[i] = arg;
	} while (arg);
	return (paths);
}
/**
 *get_paths - locate path
 *@paths: paths
 *Return: paths
 */
char **get_paths(char **paths)
{
	int i =  0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
		{
			paths = extract_paths(paths, i);
			return (paths);
		}
		i++;
	}
	paths = NULL;
	return (paths);
}
/**
 *search_path - search path
 *@command: command
 *Return: command
 */
char **search_path(char **command)
{
	char **paths;
	char *filename = malloc(sizeof(char) * 1024);
	struct stat st;
	int i = 0;
	char *arg;

	if (command == NULL)
		return (command);
	arg = command[0];
	if (arg[0] == '/' || arg[0] == '.')
		return (command);
	paths = malloc(sizeof(char *) * 64);
	if (paths == NULL)
		handle_error();
	paths = get_paths(paths);
	while (paths[i])
	{
		filename = _strcat(paths[i], "/", filename);
		filename = _strcat(filename, command[0], filename);
		if (stat(filename, &st) == 0)
		{
			command[0] = filename;
			free(paths);
			return (command);
		}
		i++;
	}
	command = NULL;
	free(paths);
	return (command);
}
