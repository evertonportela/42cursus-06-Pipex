/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/09/27 13:35:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Função para lidar com erros no programa Pipex.
 * Imprime uma mensagem de erro padrão no stderr
 * e encerra o programa com código de falha.
 */
void	ft_pipex_error(void)
{
	// Imprime uma mensagem de erro com a descrição do código de erro
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	// Encerra o programa com código de saída indicando falha.
	exit(EXIT_FAILURE);
}
