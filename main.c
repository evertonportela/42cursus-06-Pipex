/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:10 by evportel          #+#    #+#             */
/*   Updated: 2023/09/04 17:25:32 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*args[3] = {"ls", "-la", NULL};

	execve("/usr/bin/ls", args, envp);
	return (SUCCESS_PIPEX);
}
