/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/28 22:20:44 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd_input_file;
	int	fd_output_file;

	if (argc == 5)
	{
		fd_input_file = ft_open_file(argv[1], FILE_INPUT);
		if (dup2(fd_input_file, STDIN_FILENO) == -1)
			ft_pipex_error();
		close(fd_input_file);
		fd_output_file = ft_open_file(argv[4], FILE_OUTPUT);
		if (dup2(fd_output_file, STDOUT_FILENO) == -1)
			close(fd_output_file);
		close(fd_output_file);
		ft_pipex(argv[2], env);
		ft_exec_command(argv[3], env);
	}
	else
	{
		write(2, "Pipex Error: invalid number of arguments\n", 41);
		write(2, "Use: ./pipex file_input command1 command2 file_output\n", 54);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
