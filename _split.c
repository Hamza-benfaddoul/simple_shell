#include "shell.h"

/**
 * count_word - funct that calc how many word in string
 * @str: the string
 * @c: the separator
 * Return: the result as int
 */

int	count_word(char *str, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			res++;
			while (str[i] && str[i] != c)
				i++;
		}
		if (!str[i])
			return (res);
		i++;
	}
	return (res);
}

/**
 * free_all - free a two dimen array
 * @arr: the array
 * @k: the size of the array
 */

void	free_all(char **arr, int k)
{
	int	i;

	i = 0;
	while (i < k)
		free(arr[i++]);
	free(arr);

}

/**
 * _split - function that split a string and return an array of it
 * @str: the string should be splited
 * @c: the separator
 * Return: two dimension array
 */

char	**_split(char *str, char c)
{
	char	**arr;
	int	i;
	int	s;
	int	e;
	int	k;

	i = 0;
	k = 0;
	if (!str)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_word(str, c) + 1));
	while (str[i])
	{
		if (str[i] != c)
		{
			s = i;
			while (str[i] && str[i] != c)
				i++;
			e = i - 1;
			arr[k] = _substr(str, s, e);
			if (!arr[k])
				free_all(arr, k);
			k++;
		}
		else
			i++;
	}
	arr[k] = NULL;
	return (arr);
}
