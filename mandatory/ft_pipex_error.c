/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/09/30 22:46:54 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Função para lidar com erros no programa Pipex.
 * Imprime uma mensagem de erro padrão no stderr
 * e encerra o programa com código de falha.
 */
void	ft_pipex_error(int cod_exit)
{
	write(2, "PipexError: ", 12);
	// Imprime uma mensagem de erro com a descrição do código de erro
	write(2, strerror(cod_exit), ft_strlen(strerror(cod_exit)));
	write(2, "\n", 1);
	// Encerra o programa com código de saída indicando falha.
	exit(cod_exit);
}
