#include "shell.h"

/**
 * _strstr - function that search for a string in a big str
 * @str: the string where to search
 * @needed: the string needed
 * Return: the searched string
 */

char	*_strstr(char *str, char *needed)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		if (str[i] == needed[j])
		{
			temp = i;
			while (str[i] && (needed[j] == str[i]))
			{
				j++;
				i++;
			}
			if (j == _strlen(needed))
				return (str + temp);
			i = temp;
		}
		i++;
	}
	return (NULL);
}
