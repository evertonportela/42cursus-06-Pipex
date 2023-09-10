/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/09/09 19:59:51 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Função para lidar com erros no programa Pipex.
 * Imprime uma mensagem de erro padrão no stderr 
 * e encerra o programa com código de falha.
 */
void ft_pipex_error(void)
{
	perror("Pipex Error");
	exit(EXIT_FAILURE);
}
