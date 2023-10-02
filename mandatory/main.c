/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/10/02 03:06:52 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd_input_file;
	int	fd_output_file;

	if (argc == 5)
	{
		fd_output_file = ft_open_file(argv[4], FILE_OUTPUT);
		fd_input_file = ft_open_file(argv[1], FILE_INPUT);
		if (dup2(fd_input_file, STDIN_FILENO) == -1)
			ft_pipex_error(1, "fd_input");
		close(fd_input_file);
		if (dup2(fd_output_file, STDOUT_FILENO) == -1)
			ft_pipex_error(1, "fd_output");
		close(fd_output_file);
		if (ft_pipex(argv[2], env) == EXIT_FAILURE)
			ft_pipex_error(127, argv[2]);
		if (ft_exec_command(argv[3], env) == EXIT_FAILURE)
			ft_pipex_error(127, argv[3]);
	}
	else
	{
		write(2, "Use: ./pipex file_input command1 command2 file_output\n", 54);
		ft_pipex_error(22, "");
	}
	return (EXIT_SUCCESS);
}
