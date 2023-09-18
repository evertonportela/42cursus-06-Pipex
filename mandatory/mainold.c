/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:24 by evportel          #+#    #+#             */
/*   Updated: 2023/09/10 22:12:04 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Função principal do programa Pipex.
 *
 * @param argc	O número de argumentos de linha de comando.
 * @param argv	Um array de strings contendo os argumentos de linha de comando.
 * @param env	Um array de strings contendo as variáveis de ambiente.
 *
 * @return		Retorna EXIT_SUCCESS (0) se o programa for executado com sucesso
 */
int	main(int argc, char **argv, char **env)
{
	int	fd_input_file;
	int	fd_output_file;

	// Verifica se o número correto de argumentos de linha de comando
	// foi fornecido (5).
	if (argc == 5)
	{
		// Abre o arquivo de entrada no modo de leitura.
		fd_input_file = ft_open_file(argv[1], FILE_INPUT);
		
		// Redireciona a entrada padrão (stdin) para o arquivo de entrada.
		if (dup2(fd_input_file, STDIN_FILENO) == -1)
			ft_pipex_error();
		
		// Abre o arquivo de saída no modo de escrita.
		fd_output_file = ft_open_file(argv[4], FILE_OUTPUT);
		
		// Redireciona a saída padrão (stdout) para o arquivo de saída.
		if (dup2(fd_output_file, STDOUT_FILENO) == -1)
			ft_pipex_error();
		
		// Executa a primeira parte do projeto com o primeiro comando
		ft_pipex(argv[2], env);
		
		// Executa o segundo comando especificado no contexto do projeto Pipex.
		ft_exec_command(argv[3], env);
	}
	// Se o número de argumentos não for igual a 5,
	// imprime uma mensagem de erro.
	else
	{
		ft_printf("Pipex Error: invalid number of arguments\n");
		ft_printf("Use: ./pipex file_input command1 command2 file_output\n");
		exit(EXIT_FAILURE);
	}
	
	// Retorna EXIT_SUCCESS (0) para indicar sucesso.
	return (EXIT_SUCCESS);
}
