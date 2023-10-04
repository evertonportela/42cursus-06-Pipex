/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:24:57 by evportel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/03 20:40:11 by evportel         ###   ########.fr       */
=======
/*   Updated: 2023/09/27 17:40:27 by codespace        ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Executa comandos em um pipeline.
 *
 * @param command O comando a ser executado no processo filho.
 * @param env     O ambiente do sistema.
 */
int    ft_pipex(char *command, char **env)
{
    int		fd_pipe[2];     // Descritores de arquivo para o pipeline.
    pid_t   pid;            // ID do processo.

    // Cria um pipeline.
	pipe(fd_pipe);
    if (pipe(fd_pipe) == -1)
        ft_pipex_error(1, "error create fd pipe");

    // Cria um processo filho.
    pid = fork();

    // Verifica se a criação do processo filho falhou.
    if (pid < 0)
        ft_pipex_error(1, "error create pid");
    
    // Processo filho numero 1.
    if (pid == 0)
    {
		// Fecha a saída padrão do pipe preparando para fazer o redirecionamento
		close(fd_pipe[0]);

		// Aplica o redirecionamento de STDOUT padrão para a entrada do Pipe
		// A saída do comando, será a entrada do Pipe
		dup2(fd_pipe[1], STDOUT_FILENO);

		// Feito o redirecionamento, liberamos a tabela FD de entrada do Pipe
		close(fd_pipe[1]);
		
        // Executa o comando especificado.
        if (ft_exec_command(command, env) == EXIT_FAILURE)
            return (EXIT_FAILURE);

        // Sai com código de falha se algo der errado.
        exit(EXIT_FAILURE);
    }
    // Se não for um processo filho, aguarda o processo filho terminar
    else
    {
        // WNOHANG retorna imediatamente, se nenhum processo filho 
        // houver terminado
        waitpid(pid, NULL, WNOHANG);
        
        // Aplica o redirecionamento de STDIN padrão para a saída do Pipe
        dup2(fd_pipe[0], STDIN_FILENO);
        // Feito o redirecionamento, liberamos a tabela FD de entrada do Pipe
        close(fd_pipe[1]);
        // Feito o redirecionamento, liberamos a tabela FD de saída do Pipe
        close(fd_pipe[0]);
    }
    return (EXIT_SUCCESS);
}
