#include "shell.h"

/**
 * fd_putstr - put a string in a STD (1, 2 , ...)
 * @str: the string to put
 * @fd: the file descriptor
 */

void	fd_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}
