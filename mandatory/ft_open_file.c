/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/10/02 03:11:09 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open_file(char *file, int io_flag)
{
	int	fd;

	if (io_flag == FILE_INPUT)
	{
		if (access(file, F_OK) == -1)
			ft_pipex_error(2, file);
		else if (access(file, R_OK) == -1)
			ft_pipex_error(13, file);
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_pipex_error(2, file);
	}
	if (io_flag == FILE_OUTPUT)
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			ft_pipex_error(13, file);
		}
	}
	return (fd);
}
