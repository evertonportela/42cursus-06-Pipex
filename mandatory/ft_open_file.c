/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 20:59:17 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Abre um arquivo para leitura ou gravação, 
 * dependendo da bandeira de E/S especificada.
 *
 * @param file      O nome do arquivo a ser aberto.
 * @param io_flag   Uma bandeira que indica se o arquivo será aberto 
 * 					para entrada ou saída.
 *                  Deve ser FILE_INPUT para entrada e FILE_OUTPUT para saída.
 *
 * @return          O descritor de arquivo (file descriptor)
 * 					associado ao arquivo aberto, ou -1 em caso de erro.
 */
int	ft_open_file(char *file, int io_flag)
{
	int	file_descriptor;

	if (io_flag == FILE_INPUT)
	{
		if (access(file, F_OK) == -1)
			ft_pipex_error();
		file_descriptor = open(file, O_RDONLY);
		if (file_descriptor < 0)
			ft_pipex_error();
		return (file_descriptor);
	}
	else
	{
		file_descriptor = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (file_descriptor < 0)
			ft_pipex_error();
		return (file_descriptor);
	}
}
