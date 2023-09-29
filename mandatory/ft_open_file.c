/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/28 22:28:47 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open_file(char *file, int io_flag)
{
	int	fd;

	if (io_flag == FILE_INPUT)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "Pipex Error: Failed to open file:", 34);
		write(2, file, ft_strlen(file));
		exit(EXIT_FAILURE);
	}
	return (fd);
}
