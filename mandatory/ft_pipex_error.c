/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 23:03:48 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex_error(void)
/**
 * Função para lidar com erros no programa Pipex.
 * Imprime uma mensagem de erro padrão no stderr
 * e encerra o programa com código de falha.
 */
{
	perror("Pipex Error");
	exit(EXIT_FAILURE);
}
