/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/27 01:10:46 by codespace        ###   ########.fr       */
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
	int	file_descriptor;

	// Abre o arquivo para entrada.
	if (io_flag == FILE_INPUT)
	{
		// Verifica se o arquivo existe.
		if (access(file, F_OK) != 0)
			ft_pipex_error();
		// ou se tem permissão de acesso
		else if (access(file, X_OK) != 0)
			ft_pipex_error();
		
		// Abre o arquivo para leitura apenas.
		file_descriptor = open(file, O_RDONLY);
		
		// Verifica se a abertura do arquivo falhou.
		if (file_descriptor < 0)
			ft_pipex_error();
	}
	
	// Abre o arquivo para saída.
	else
	{
		// Abre o arquivo para leitura e gravação,
		// cria se não existir e define permissões.
		file_descriptor = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		
		// Verifica se a abertura do arquivo falhou.
		if (file_descriptor < 0)
			ft_pipex_error();
	}

	// Retorna o descritor de arquivo após a abertura bem-sucedida.
	return (file_descriptor);
}
