#include "shell.h"

/**
 * is_built_in - function to execute the built in cmd
 * @ptr: pointer to the structur
 * @env: the envirement
 * Return: 0 if true or 1 if not
 */

int	is_built_in(t_data *ptr, char **env)
{
	int	i;

	i = 0;
	if (_strcmp(ptr->line, "env") == 0)
	{
		while (env[i])
		{
			fd_putstr(env[i], 1);
			fd_putstr("\n", 1);
			i++;
		}
		return (0);
	}
	else if (_strcmp(ptr->line, "exit") == 0)
	{
		free(ptr->line);
		if (ptr->args)
			free_split(ptr->args);
		exit(ptr->exit_s);
	}
	return (1);
}
