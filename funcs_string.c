#include "_shell.h"
/**
 *_putchar - _putchar
 *@c: char
 *Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *_strlen - lenght of string
 *@str: string
 *Return: int
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	if (str[0] == '\0')
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 *_strcpy - copy string
 *@out: string out
 *@in: string in
 *Return: string
 */
char *_strcpy(char *out, char *in)
{
	int i = 0;

	if (in == NULL)
		return (NULL);
	while (in[i] != '\0')
	{
		out[i] = in[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
/**
 *_strcat - concatenate string
 *@a: string
 *@b: string
 *@c: string
 *Return: string
 */
char *_strcat(char *a, char *b, char *c)
{
	int len_a = _strlen(a);
	int len_b = _strlen(b);
	int i = 0;

	c = realloc(c, len_a + len_b + 1);
	while (a[i] != '\0')
	{
		c[i] = a[i];
		i++;
	}
	while (b[i - len_a] != '\0')
	{
		c[i] = b[i - len_a];
		i++;
	}
	c[i] = '\0';
	return (c);
}
