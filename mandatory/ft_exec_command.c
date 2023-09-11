/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:23:20 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 23:13:01 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Obtém e manipula as variáveis de ambiente relacionadas ao PATH.
 *
 * @param env	O array de strings contendo as variáveis de ambiente.
 *
 * @return		Um novo array de strings contendo diretórios do PATH com
 * 				barras '/' adicionadas no final.
 * 				Retorna NULL se a variável de ambiente "PATH"
 * 				não for encontrada.
 */
static char	**ft_get_path_command(char **env)
{
	int		index;
	char	**env_all_path;
	char	*env_temp;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	if (env[index] == 0)
		return (NULL);
	env_all_path = ft_split((env[index] + 5), ':');
	index = 0;
	while (env_all_path[index])
	{
		env_temp = env_all_path[index];
		env_all_path[index] = ft_strjoin(env_temp, "/");
		free(env_temp);
		index++;
	}
	return (env_all_path);
}

/**
 * Procura o caminho completo (path) de um executável de comando especificado 
 * nas variáveis de ambiente.
 *
 * @param command	O nome do comando a ser encontrado.
 * @param env		O array de strings contendo as variáveis de ambiente.
 *
 * @return			O caminho completo do comando se encontrado e executável,
 * 					ou NULL se não encontrado.
 */
static char	*ft_find_command_path(char *command, char **env)
{
	int		index;
	char	*command_path;

	env = ft_get_path_command(env);
	index = 0;
	while (env[index])
	{
		command_path = ft_strjoin(env[index], command);
		if (access(command_path, F_OK | X_OK) == 0)
			return (command_path);
		free(command_path);
		index++;
	}
	return (NULL);
}

/**
 * Executa um comando especificado no contexto do projeto Pipex.
 *
 * @param command	O comando a ser executado como uma string.
 * @param env		O array de strings contendo as variáveis de ambiente.
 */
void	ft_exec_command(char *command, char **env)
{
	char	**command_args;
	char	*path_exec;

	command_args = ft_split(command, ' ');
	path_exec = ft_find_command_path(command_args[0], env);
	execve(path_exec, command_args, env);
	ft_printf("Pipex Error: Command not found: ");
	exit(127);
}
