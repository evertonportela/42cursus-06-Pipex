/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:23:20 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 22:35:48 by evportel         ###   ########.fr       */
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
	
	// Encontra a variável de ambiente "PATH="
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	
	// Verifica se a variável de ambiente "PATH" não foi encontrada.
	if (env[index] == 0)
		return (NULL);
	
	// Divide a string após "PATH=" usando ':' como delimitador
	env_all_path = ft_split((env[index] + 5), ':');
	index = 0;
	
	// Adiciona '/' ao final de cada diretório do PATH
	while (env_all_path[index])
	{
		env_temp = env_all_path[index];
		env_all_path[index] = ft_strjoin(env_temp, "/");
		free(env_temp);
		index++;
	}
	
	// Retorna o array de strings contendo os diretórios do PATH
	// com barras '/' adicionadas no final.
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

	// Obtém e processa os diretórios do PATH a partir das variáveis de ambiente
	env = ft_get_path_command(env);
	index = 0;
	
	// Itera por todos os diretórios do PATH.
	while (env[index])
	{
		// Concatena o nome do comando com o diretório atual do PATH.
		command_path = ft_strjoin(env[index], command);
		
		// Verifica se o comando existe e é executável no caminho atual.
		if (access(command_path, F_OK | X_OK) == 0)
			return (command_path);
		
		// Libera a memória alocada para o caminho.
		free(command_path);
		index++;
	}
	
	// Retorna NULL se o comando não for encontrado em nenhum diretório do PATH.
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

	// Divide a string do comando em argumentos individuais.
	command_args = ft_split(command, ' ');
	
	// Encontra o caminho completo para o executável do comando.
	path_exec = ft_find_command_path(command_args[0], env);
	
	// Executa o comando no contexto do processo atual.
	execve(path_exec, command_args, env);
	
	// Se a execução do comando falhar, imprime uma mensagem de erro.
	ft_printf("Pipex Error: Command not found: ");
	
	// Sai com um código de saída indicando que o comando não foi encontrado.
	exit(127);
}
