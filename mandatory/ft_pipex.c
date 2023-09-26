/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:24:57 by evportel          #+#    #+#             */
/*   Updated: 2023/09/26 20:44:52 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * Executa comandos em um pipeline.
 *
 * @param command O comando a ser executado no processo filho.
 * @param env     O ambiente do sistema.
 */
void    ft_pipex_one(char *file, char *command, char **env)
{
    int     fd_input_file;
	//int     fd_output_file;
    int     fd_pipe[2];     // Descritores de arquivo para o pipeline.
    pid_t   pid;            // ID do processo.

    // Cria um pipeline.
    if (pipe(fd_pipe) == -1)
        ft_pipex_error();

    // Cria um processo filho.
    pid = fork();

    // Verifica se a criação do processo filho falhou.
    if (pid == -1)
        ft_pipex_error();
    
    // Processo filho numero 1.
    if (pid == 0)
    {
        // Abre o arquivo de entrada no modo de leitura.
		fd_input_file = ft_open_file(file, FILE_INPUT);
		
		// Redireciona a entrada padrão (stdin) para o arquivo de entrada.
		if (dup2(fd_input_file, STDIN_FILENO) == -1)
			ft_pipex_error();
        
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
    // Processo segundo processo filho.
    else
    {
        ft_printf("Deu ruim");
        // Abre o arquivo de saída no modo de escrita.
		// fd_output_file = ft_open_file(file, FILE_OUTPUT);
		
		// Redireciona a saída padrão (stdout) para o arquivo de saída.
		// if (dup2(fd_output_file, STDOUT_FILENO) == -1)
		// 	ft_pipex_error();
        
        // Espera pelo término do processo filho.
        // waitpid(pid, NULL, 0);

        // Redireciona a entrada padrão para o descritor de leitura do pipeline.
        // dup2(fd_pipe[STDIN_FILENO], STDIN_FILENO);

        // Fecha os descritores de arquivo do pipeline.
        // close(fd_pipe[STDOUT_FILENO]);
        // close(fd_pipe[STDIN_FILENO]);
    }
}

void    ft_pipex_two(char *file, char *command, char **env)
{
    //int     fd_input_file;
	int     fd_output_file;
    int     fd_pipe[2];     // Descritores de arquivo para o pipeline.
    pid_t   pid;            // ID do processo.

    // Cria um pipeline.
    if (pipe(fd_pipe) == -1)
        ft_pipex_error();

    // Cria um processo filho.
    pid = fork();

    // Verifica se a criação do processo filho falhou.
    if (pid == -1)
        ft_pipex_error();
    
    // Processo filho numero dois.
    if (pid == 0)
    {
        // Abre o arquivo de entrada no modo de leitura.
		fd_output_file = ft_open_file(file, FILE_OUTPUT);
		
		// Redireciona a entrada padrão (stdin) para o arquivo de entrada.
		if (dup2(fd_output_file, STDOUT_FILENO) == -1)
			ft_pipex_error();
        
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
    // Processo segundo processo filho.
    else
    {
        ft_printf("Deu ruim");
        // Abre o arquivo de saída no modo de escrita.
		// fd_output_file = ft_open_file(file, FILE_OUTPUT);
		
		// Redireciona a saída padrão (stdout) para o arquivo de saída.
		// if (dup2(fd_output_file, STDOUT_FILENO) == -1)
		// 	ft_pipex_error();
        
        // Espera pelo término do processo filho.
        // waitpid(pid, NULL, 0);

        // Redireciona a entrada padrão para o descritor de leitura do pipeline.
        // dup2(fd_pipe[STDIN_FILENO], STDIN_FILENO);

        // Fecha os descritores de arquivo do pipeline.
        // close(fd_pipe[STDOUT_FILENO]);
        // close(fd_pipe[STDIN_FILENO]);
    }
}