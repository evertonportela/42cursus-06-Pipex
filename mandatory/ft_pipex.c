/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:24:57 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 20:50:33 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex(char *command, char **env)
{
	int		fd_pipe[2];
	pid_t	pid;

	if (pipe(fd_pipe) == -1)
		ft_pipex_error();
	pid = fork();
	if (pid == -1)
		ft_pipex_error();
	else if (pid == 0)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[1]);
		ft_exec_command(command, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		dup2(fd_pipe[0], STDIN_FILENO);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
	}
}
