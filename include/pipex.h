/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:26:32 by evportel          #+#    #+#             */
/*   Updated: 2023/09/05 21:08:51 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define SUCCESS_PIPEX 0
# define ERROR_PIPEX 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* Funtions Projects 42 ***************************************************** */
# include "../libraries/libft/libft.h"

/* Funtions Pipex *********************************************************** */
int	ft_check_param(int argc, char *argv[], char *envp[]);

#endif
