/*
 * Aula 02 - Criação de processos com fork() e observação de um processo zumbi.
 *
 * O filho termina imediatamente, mas o pai não chama wait(); enquanto o pai estiver
 * em execução, o filho aparece como <defunct> (zumbi) em `ps`. Encerre com Ctrl+C.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    printf("Eu sou o processo pai: meu PID = %d\n", getpid());

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Processo filho: termina sem que o pai colete seu status.
        exit(EXIT_SUCCESS);
    }

    printf("O PID do filho = %d\n", pid);
    printf("Observe o processo zumbi com: ps -o pid,ppid,stat,cmd --ppid %d\n", getpid());

    for (;;) {
        pause(); // mantém o pai vivo sem consumir CPU
    }
}
