/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:10 by evportel          #+#    #+#             */
/*   Updated: 2023/09/05 22:14:26 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_param(int argc, char *argv[], char *envp[])
{
	int	fd_input;

	errno = EINVAL;
	if (argc == 5)
	{
		fd_input = open(argv[1], );
		return (SUCCESS_PIPEX);
	}
	else
		perror("Invalid number of input parameters");
}

int	main(int argc, char *argv[], char *envp[])
{
	if (ft_check_param(argc, argv, envp) == ERROR_PIPEX)
		return (ERROR_PIPEX);
	return (SUCCESS_PIPEX);
}

	// char	*args[3] = {"ls", "-la", NULL};
	// execve("/usr/bin/ls", args, envp);