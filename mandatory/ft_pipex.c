/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:24:57 by evportel          #+#    #+#             */
/*   Updated: 2023/09/09 21:22:21 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex(char *command, char **env)
{
	int		fd_pipe[2];
	pid_t	pid;
	
	if(pipe(fd_pipe) == -1)
		ft_pipex_error();
	pid = fork();
	if (pid == -1)
		ft_pipex_error();
	else if (pid == 0)
	{
		close(fd_pipe[STDIN_FILENO]);
		du2(fd_pipe[STDOUT_FILENO], STDOUT_FILENO);
		close(fd_pipe[STDOUT_FILENO]);
		ft_exec_command(command, env);
	}
}
