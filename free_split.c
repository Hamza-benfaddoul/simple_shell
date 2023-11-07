#include "shell.h"

/**
 * free_split - free an array that allocated with split
 * @arr: the array
 */

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
