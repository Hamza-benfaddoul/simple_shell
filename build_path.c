#include "shell.h"

/**
 * loop_env - loop throw env
 * @env: the envirment
 * @new_cmd: the new cmd to execute
 * Return: the index of PATH in evn **
 */

int	loop_env(char **env, char **new_cmd)
{
	char	**check;
	int	cmp;
	int	i;

	i = 0;
	new_cmd += 0;
	while (env[i])
	{
		check = _split(env[i], '=');
		cmp = _strcmp(check[0], "PATH");
		if (cmp != 0)
			i++;
		else
		{
			*new_cmd = _strdup(check[1]);
			free_split(check);
			return (i);
		}
		free_split(check);
	}
	return (i);
}

/**
 * build_path - build the path of the cmd ls => /bin/ls
 * @ptr: the pointer to the struct
 * @env: the envirment vaiable
 * Return: 0 if the path found -1 if not
 */

int	build_path(t_data *ptr, char **env)
{
	int	ret;
	char	*new_cmd;
	int	i;
	char	**path;
	char	*temp;

	i = 0;
	new_cmd = NULL;
	ptr->args = _split(ptr->line, ' ');
	if (!ptr->args[0])
		return (404);
	ret = access(ptr->args[0], F_OK);
	if (ret == 0)
	{
		free(ptr->line);
		ptr->line = _strdup(ptr->args[0]);
		return (0);
	}
	i = loop_env(env, &new_cmd);
	if (env[i] == NULL)
		return (-1);
	path = _split(new_cmd, ':');
	free(new_cmd);
	i = 0;
	temp = _strjoin("/", ptr->args[0]);
	while (path[i])
	{
		free(ptr->line);
		ptr->line = _strjoin(path[i], temp);
		ret = access(ptr->line, F_OK);
		if (ret == 0)
			return (free_split(path), free(temp), 0);
		i++;
	}
	return (free_split(path), free(temp), -1);
}

