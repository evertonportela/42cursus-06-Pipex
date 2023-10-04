/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:32 by evportel          #+#    #+#             */
/*   Updated: 2023/10/03 21:11:35 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* Variaveis de leitura dos arquivos informados nos parametros ************** */
# define FILE_INPUT 0
# define FILE_OUTPUT 1

/* Include Projects 42 ****************************************************** */
# include "../libft/libft.h"

/* Inclusões necessárias para o projeto Pipex ******************************* */
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/* Funções do Projeto Pipex ************************************************* */
int		ft_open_file(char *file, int io_flag);
void	ft_pipex_error(int cod_exit, char *str);
int		ft_pipex(char *command, char **env);
int		ft_exec_command(char *command, char **env);

#endif
