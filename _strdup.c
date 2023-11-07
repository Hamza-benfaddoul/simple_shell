#include "shell.h"

/**
 * _strdup - alloc for a copy of a string
 * @str: the string
 * Return: the new string allocated with malloc
 */

char	*_strdup(char *str)
{
	char	*new;
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	new = malloc((_strlen(str) + 1) * sizeof(char));
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
