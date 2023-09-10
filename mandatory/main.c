/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/09 22:16:07 by evportel         ###   ########.fr       */
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
		fd_output_file = ft_open_file(argv[4], FILE_OUTPUT);
		if (dup2(fd_output_file, STDOUT_FILENO) == -1)
			ft_pipex_error();
		ft_pipex(argv[2], env);
	}
	return (EXIT_SUCCESS);
}

/** nota para o everton do futuro 
 * continuar o raciocinio a partir do ft_find_command_path()
 * no arquivo ft_exec_command
*/