/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:23:20 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 21:03:01 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**ft_get_path_command(char **env)
{
	int		index;
	char	**env_all_path;
	char	*env_temp;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	if (env[index] == 0)
		return (NULL);
	env_all_path = ft_split((env[index] + 5), ':');
	index = 0;
	while (env_all_path[index])
	{
		env_temp = env_all_path[index];
		env_all_path[index] = ft_strjoin(env_temp, "/");
		free(env_temp);
		index++;
	}
	return (env_all_path);
}

static char	*ft_find_command_path(char *command, char **env)
{
	int		index;
	char	*command_path;

	env = ft_get_path_command(env);
	index = 0;
	while (env[index])
	{
		command_path = ft_strjoin(env[index], command);
		if (access(command_path, F_OK | X_OK) == 0)
			return (command_path);
		free(command_path);
		index++;
	}
	return (NULL);
}

void	ft_exec_command(char *command, char **env)
{
	char	**command_args;
	char	*path_exec;

	command_args = ft_split(command, ' ');
	path_exec = ft_find_command_path(command_args[0], env);
	execve(path_exec, command_args, env);
	ft_printf("Pipex Error: Command not found: ");
	exit(127);
}
