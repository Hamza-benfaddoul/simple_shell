#include "shell.h"

/**
 * _strlen - function that calc the length of a string
 * @str: the stirng
 * Return: the length of str
 */

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
