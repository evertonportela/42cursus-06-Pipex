#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int execute_cmd(char *cmd, int input_fd, int output_fd) {
    pid_t pid;
    int status;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Processo filho
        if (input_fd != STDIN_FILENO) {
            if (dup2(input_fd, STDIN_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(input_fd);
        }

        if (output_fd != STDOUT_FILENO) {
            if (dup2(output_fd, STDOUT_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(output_fd);
        }

        // Executar o comando
        char *argv[] = {"/bin/sh", "-c", cmd, NULL};
        execve("/bin/sh", argv, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    } else {  // Processo pai
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Erro: O comando \"%s\" falhou.\n", cmd);
            exit(EXIT_FAILURE);
        }
    }

    return pid;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Uso: %s file1 cmd1 cmd2 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *file1 = argv[1];
    char *cmd1 = argv[2];
    char *cmd2 = argv[3];
    char *file2 = argv[4];

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid1 = execute_cmd(cmd1, open(file1, O_RDONLY), pipefd[WRITE_END]);
    int pid2 = execute_cmd(cmd2, pipefd[READ_END], open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644));

    close(pipefd[READ_END]);
    close(pipefd[WRITE_END]);

    // Esperar pela conclusão dos processos filhos
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
