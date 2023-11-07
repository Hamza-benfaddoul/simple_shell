#include "shell.h"

/**
 * _strjoin - join two string
 * @s1: the firt string
 * @s2: the second string
 * Return: the joing string
 */

char	*_strjoin(char *s1, char *s2)
{
	char	*new;
	int	i;
	int	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (_strdup(s2));
	if (!s2)
		return (_strdup(s1));
	new = malloc(_strlen(s1) + _strlen(s2) + 1);
	j = 0;
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
