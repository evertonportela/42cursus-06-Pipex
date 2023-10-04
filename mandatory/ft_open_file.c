/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/10/03 21:11:07 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Abre um arquivo para leitura ou gravação no contexto do projeto Pipex.
 *
 * @param file		O nome do arquivo a ser aberto.
 * @param io_flag	Um indicador que determina se o arquivo será aberto para
 * 					entrada ou saída.
 *					Use `FILE_INPUT` para abrir para entrada e `FILE_OUTPUT`
 *					para saída.
 *
 * @return			O descritor de arquivo do arquivo aberto se a operação
 * 					for bem-sucedida.
 *					A função `ft_pipex_error()` é chamada em caso de erro e o
 *					programa é encerrado.
 */
int	ft_open_file(char *file, int io_flag)
{
	int	fd;
	// Abre o arquivo para entrada.
	if (io_flag == FILE_INPUT)
	{
		if (access(file, F_OK) == -1)
		{
			// o código de erro 2 para ENOENT 'no such file or directory'
			ft_pipex_error(2, file);
		}
		else if (access(file, R_OK) == -1)
		{
			// o código de erro 0 para EXIT_SUCCESS 'indica sucesso'
			// é o que o bash considera, apesar de de falhar.
			ft_pipex_error(13, file);
		}
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			// o código de erro 2 para ENOENT 'no such file or directory'
			ft_pipex_error(2, file);
		}
	}
	// Abre o arquivo para saída.
	if (io_flag == FILE_OUTPUT)
	{
		// Retorna o descritor de arquivo após a abertura bem-sucedida.
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		//	Verifica se a abertura do arquivo falhou
		if (fd == -1)
		{
			// apesar do erro sero código de erro 13 para EACCES 'Permission denied'
			ft_pipex_error(13, file);	
		}
	}
	return (fd);
}
