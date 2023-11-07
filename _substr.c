#include "shell.h"

/**
 * _substr - function that cut a string from start to end (index)
 * @str: the string
 * @s: the starting index
 * @e: the last char at index (e)
 * Return: the substring pointer
 */

char	*_substr(char *str, int s, int e)
{
	char	*res;
	int	size;
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (s >= e)
		return (_strdup(""));
	size = e - s + 2;
	res = malloc(size * sizeof(char));
	while (s <= e)
	{
		res[i++] = str[s++];
	}
	res[i] = '\0';
	return (res);
}
