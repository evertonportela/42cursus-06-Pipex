/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/10/03 21:10:49 by evportel         ###   ########.fr       */
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
	// Imprime uma mensagem de erro com um prefixo "Pipex Error"
	perror("Pipex Error");
	// Encerra o programa com código de saída indicando falha.
	exit(EXIT_FAILURE);
}
