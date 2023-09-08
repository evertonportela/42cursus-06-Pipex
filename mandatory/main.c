/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/08 16:58:25 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	char	*fileinput = argv[1];
	char	*command1 = argv[2];
	char	*command2 = argv[3];
	char	*fileoutput = argv[4];
	int		pipefd[2];
	int		fd_input;

	if (argc != 5)
	{
		ft_printf("Invalid argument: ");
		ft_printf("Use %s input command1 command2 output", argv[0]);
		exit(P_ERROR);
	}
	if (access(fileinput, F_OK) != 0)
	{
		perror("pipex:");
		exit(P_ERROR);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipex:");
		exit(P_ERROR);
	}
	fd_input = open(fileinput, O_RDONLY);
	if (fd_input == -1)
		perror("Erro ao abrir arquivo");
	return (P_SUCCESS);
}
