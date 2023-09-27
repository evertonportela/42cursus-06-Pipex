/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/27 20:56:32 by codespace        ###   ########.fr       */
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
		// Verifica se o arquivo existe.
		// if (access(file, F_OK | X_OK) != 0)
		//	ft_pipex_error();
		// ou se tem permissão de acesso
		fd = open(file, O_RDONLY);
	}
	// Abre o arquivo para saída.
	else
	{
		// Retorna o descritor de arquivo após a abertura bem-sucedida.
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	//	Verifica se a abertura do arquivo falhou
	if (fd == -1)
	{
		write(2, "Pipex Error: Failed to open file:", 34);
		write(2, file, ft_strlen(file));
		exit(EXIT_FAILURE);
	}
	return (fd);
}
