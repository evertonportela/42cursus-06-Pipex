/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:24:57 by evportel          #+#    #+#             */
/*   Updated: 2023/09/18 20:58:56 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Executa comandos em um pipeline.
 *
 * @param command O comando a ser executado no processo filho.
 * @param env     O ambiente do sistema.
 */
void ft_pipex(char *command, char **env)
{
    int fd_pipe[2];  // Descritores de arquivo para o pipeline.
    pid_t pid;       // ID do processo.

    // Cria um pipeline.
    if (pipe(fd_pipe) == -1)
        ft_pipex_error();

    // Cria um processo filho.
    pid = fork();

    // Verifica se a criação do processo filho falhou.
    if (pid == -1)
        ft_pipex_error();
    
    // Processo filho.
    if (pid == 0)
    {
        // Fecha o descritor de leitura do pipeline.
        close(fd_pipe[STDIN_FILENO]);

        // Redireciona a saída padrão para o descritor de escrita do pipeline.
        dup2(fd_pipe[STDOUT_FILENO], STDOUT_FILENO);

        // Fecha o descritor de escrita do pipeline.
        close(fd_pipe[STDOUT_FILENO]);

        // Executa o comando especificado.
        ft_exec_command(command, env);

        // Sai com código de falha se algo der errado.
        exit(EXIT_FAILURE);
    }
    // Processo pai.
    else
    {
        // Espera pelo término do processo filho.
        waitpid(pid, NULL, 0);

        // Redireciona a entrada padrão para o descritor de leitura do pipeline.
        dup2(fd_pipe[STDIN_FILENO], STDIN_FILENO);

        // Fecha os descritores de arquivo do pipeline.
        close(fd_pipe[STDOUT_FILENO]);
        close(fd_pipe[STDIN_FILENO]);
    }
}