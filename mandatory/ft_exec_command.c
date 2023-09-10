/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:23:20 by evportel          #+#    #+#             */
/*   Updated: 2023/09/09 22:03:15 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*ft_find_command_path(char *command, char **env)
{
	int		index;
	// char	*env_path_start;
	char	**env_all_path;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	if (env[index] == '\0')
		return (NULL);
	// env_path_start = env[index] + 5;
	// env_all_path = ft_split(env_path_start, ':');
	env_all_path = ft_split((env[index] + 5), ':');
	index = 0;
	while (env_all_path[index])
	{
		
	}
}

void	ft_exec_command(char *command, char **env)
{
	char	**command_args;
	char	*path_exec;

	command_args = ft_split(command, ' ');
	path_exec = ft_find_command_path();
}
