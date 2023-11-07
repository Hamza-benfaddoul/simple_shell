#include "shell.h"

/**
 * _strcmp - compare between two string
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if they are equal or !0 if not
 */

int	_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (-1);
	}
	return (0);
}
