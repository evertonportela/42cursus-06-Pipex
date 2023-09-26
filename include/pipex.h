/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:32 by evportel          #+#    #+#             */
/*   Updated: 2023/09/26 20:47:06 by evportel         ###   ########.fr       */
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
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

/* Funções da estrutura Pipex *********************************************** */
int		ft_open_file(char *file, int io_flag);
void	ft_pipex_error(void);
//void	ft_pipex(char *file, char *command, char **env);
void	ft_pipex_one(char *file, char *command, char **env);
void	ft_pipex_two(char *file, char *command, char **env);
void	ft_exec_command(char *command, char **env);

#endif
