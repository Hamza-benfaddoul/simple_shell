#include "shell.h"

/**
 * init_data - init the struct with default values
 * @ptr: the addrs of the struct
 * @av: list of argument
 */

void	init_data(t_data *ptr, char **av)
{
	ptr->len = 0;
	ptr->ret = 0;
	ptr->av = av;
	ptr->args = NULL;
	ptr->exit_s = 0;
	ptr->line = NULL;
	ptr->error = 1;
}

/**
 * clear_data - the end of the program
 * @ptr: the ponter to the struct
 */

void	clear_data(t_data *ptr)
{
	free(ptr->line);
	if (ptr->args)
		free_split(ptr->args);
	free(ptr);
}

/**
 * handle_error - handle error
 * @ptr: the pointer to the structur
 */

void	handle_error(t_data *ptr)
{
	if (ptr->ret != 404)
	{
		fd_putstr(ptr->av[0], 2);
		fd_putstr(": ", 2);
		_putnbr(ptr->error);
		fd_putstr(": ", 2);
		fd_putstr(ptr->line, 2);
		fd_putstr(": not found\n", 2);
		ptr->exit_s = 127;
	}
	free(ptr->line);
	ptr->line = NULL;
	free_split(ptr->args);
	ptr->args = NULL;
	ptr->error++;
}

/**
 * main - the start of the program
 * @ac: the length of the argv
 * @av: array of arguments
 * @env: the envirement
 * Return: the exit status of the shell
 */

int	main(int ac, char **av, char **env)
{
	t_data	*ptr;

	ptr = malloc(sizeof(t_data));
	init_data(ptr, av);
	while ((ptr->read = getline(&ptr->line, &ptr->len, stdin)) != -1)
	{
		if (ptr->line)
			ptr->line[_strlen(ptr->line) - 1] = '\0';
		if (is_built_in(ptr, env) == 0)
		{
			free(ptr->line);
			ptr->line = NULL;
			continue;
		}
		ptr->ret = build_path(ptr, env);
		if (ptr->ret == -1 || ptr->ret == 404)
		{
			handle_error(ptr);
			continue;
		}
		ptr->pid = fork();
		if (ptr->pid < 0)
			perror("fork");
		if (ptr->pid == 0)
		{
			if (execve(ptr->line, ptr->args, env) == -1)
			{
				perror(av[0]);
				exit(2);
			}
		}
		wait(&ptr->exit_s);
		free_split(ptr->args);
		ptr->args = NULL;
		free(ptr->line);
		ptr->line = NULL;
	}
	clear_data(ptr);
	return (0);
}
