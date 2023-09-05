/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:56:33 by evportel          #+#    #+#             */
/*   Updated: 2023/09/05 17:59:48 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_param(int argc, char *argv[], char *envp[])
{
	errno = EINVAL;
	if (argc == 5)
		ft_printf("Ok bora trabalhar -> Birl\n");
	else
		perror("Invalid number of input parameters");
	return (SUCCESS_PIPEX);
}
