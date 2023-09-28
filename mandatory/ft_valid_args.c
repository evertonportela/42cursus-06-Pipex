/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:52:40 by codespace         #+#    #+#             */
/*   Updated: 2023/09/28 01:11:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_valid_args(char **args)
{
	if (access(args[1], F_OK) == -1)
	{
		perror("Erro ao verificar arquivo de entrada");
		exit(EXIT_FAILURE);
	}
	if (access(args[2], X_OK) == -1)
	{
		fprintf(stderr, "Erro: O comando 1 não é executável ou não existe.\n");
		exit(EXIT_FAILURE);
	}
	if (access(args[3], X_OK) == -1)
	{
		fprintf(stderr, "Erro: O comando 2 não é executável ou não existe.\n");
		exit(EXIT_FAILURE);
	}
}
