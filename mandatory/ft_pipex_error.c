/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/10/01 17:39:43 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Função que lida com erros do programa pipex.
 *
 * Esta função exibe mensagens de erro no stderr e encerra o programa com um 
 * código de saída apropriado.
 *
 * @param cod_exit O código de erro a ser exibido (geralmente um valor retornado
 * por outra função).
 * @param str Uma string de descrição opcional para o erro.
 *
 * @return A função não retorna um valor, mas termina o programa com um código
 * de saída apropriado.
 */
void	ft_pipex_error(int cod_exit, char *str)
{
	// Exibe "PipexError: " no stderr.
	write(2, "PipexError: ", 12);
	
	// Exibe a mensagem de erro correspondente ao código de saída.
	if (cod_exit == 127)
		write(2, "command not found", 18);
	else
		write(2, strerror(cod_exit), ft_strlen(strerror(cod_exit)));
	
	// Exibe a descrição adicional do erro, se fornecida.
	if (str[0] != 0)
	{
		write(2, ": ", 2);
		write(2, &str[0], ft_strlen(&str[0]));
	}

	// Exibe uma quebra de linha no stderr.
	write(2, "\n", 1);

    // Encerra o programa com um código de saída apropriado,
	// dependendo do código de erro.
	if (cod_exit == 0)
		exit(cod_exit);
	else
		exit(EXIT_FAILURE);
}
