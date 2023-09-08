/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/08 18:09:38 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int ft_exec_cmd(char *command, int input_fd, int output_fd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("pipex:");
		exit(P_ERROR);
	}
	/** PROCESSO PAI */
	if (pid == 0)
	{
		if (input_fd != STDIN_FILENO)
		{
			if (dup2(input_fd, STDIN_FILENO) == -1)
			{
				perror("dup2:");
				exit(P_ERROR);
			}
			close(input_fd);
		}
		if (output_fd != STDOUT_FILENO)
		{
			if (dup2(output_fd, STDOUT_FILENO) == -1)
			{
				perror("dup2:");
				exit(P_ERROR);
			}
			close(output_fd);
		}
		/* Executar o comando */
        execve("/bin/sh", (char *[]){"/bin/sh", "-c", command, NULL}, env);
        // perror("execve");
        // exit(EXIT_FAILURE);
	}
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	char	*fileinput = argv[1];
	char	*command1 = argv[2];
	char	*command2 = argv[3];
	char	*fileoutput = argv[4];
	int		pipefd[2];
	int		fd_input;
	int		pid_cmd_1;
	int		pid_cmd_2;

	if (argc != 5)
	{
		ft_printf("Invalid argument: ");
		ft_printf("Use %s input command1 command2 output", argv[0]);
		exit(P_ERROR);
	}
	if (access(fileinput, F_OK) != 0)
	{
		perror("access:");
		exit(P_ERROR);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe:");
		exit(P_ERROR);
	}
	fd_input = open(fileinput, O_RDONLY);
	if (fd_input == -1)
		perror("Erro ao abrir arquivo");
	pid_cmd_1 = ft_exec_cmd(command1, open(fileinput, O_RDONLY), pipefd[P_WRITE], env);
	pid_cmd_2 = ft_exec_cmd(command2, pipefd[P_READ], open(fileoutput, O_WRONLY | O_CREAT | O_TRUNC, 0644), env);
	close(pipefd[P_READ]);
	close(pipefd[P_WRITE]);
	waitpid(pid_cmd_1, NULL, 0);
	waitpid(pid_cmd_2, NULL, 0);
	return (P_SUCCESS);
}
