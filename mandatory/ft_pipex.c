/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:24:57 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 23:06:50 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Executa comandos em um pipeline.
 *
 * @param command O comando a ser executado no processo filho.
 * @param env     O ambiente do sistema.
 */
void	ft_pipex(char *command, char **env)
{
	pid_t	pid;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		ft_pipex_error();
	pid = fork();
	if (pid == -1)
		ft_pipex_error();
	if (pid == 0)
	{
		close(fd_pipe[STDIN_FILENO]);
		dup2(fd_pipe[STDOUT_FILENO], STDOUT_FILENO);
		close(fd_pipe[STDOUT_FILENO]);
		ft_exec_command(command, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd_pipe[STDIN_FILENO], STDIN_FILENO);
		close(fd_pipe[STDOUT_FILENO]);
		close(fd_pipe[STDIN_FILENO]);
	}
}
