/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:10 by evportel          #+#    #+#             */
/*   Updated: 2023/09/07 11:14:48 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_pipe[2];

	pipe(fd_pipe);
	if (argc != 5)
	{
		errno = EINVAL;
		ft_printf("use: input_file \"cmd_1\" \"cmd_2\" output_file\n");
		perror("pipex");
		exit (STDERR_FILENO);
	}
	if (access(argv[1], F_OK) != 0)
	{
		ft_printf("Access File Error\n");
		perror("pipex");
		exit (STDERR_FILENO);
	}
	ft_printf("Args OK - File OK\n");
	return (SUCCESS_PIPEX);
}

/**

char	*args[3] = {"ls", "-la", NULL};
execve("/usr/bin/ls", args, envp);

$> ./pipex infile "ls -l" "wc -l" outfile

*/