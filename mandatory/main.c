/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:10 by evportel          #+#    #+#             */
/*   Updated: 2023/09/05 13:07:52 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (ft_check_param(argc, argv, envp) == ERROR_PIPEX)
		return (ERROR_PIPEX);
	return (SUCCESS_PIPEX);
}

	// char	*args[3] = {"ls", "-la", NULL};
	// execve("/usr/bin/ls", args, envp);