#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    char str[40];
    int continua = 1, res, pid, estado;

    pid = getpid();
    while (continua) {
        printf("[%d]Comando: ", getpid());
        fflush(stdout);
        scanf("%s", str);
        if (strcmp(str, "sair") != 0) {
            res = fork(); // criar processo filho
            if (res == 0) { // FILHO
                pid = getpid();
                printf("[%5d] FILHO: Sou o filho...\n", getpid());
                execl(str, str, NULL);
                printf("[ERRO] Nao consegui executar a aplicacao\n");
                exit(7);
            }
            printf("[%5d] PAI: Criei o filho PID=%d...\n", pid, res);
            wait(&estado);
            if (WIFEXITED(estado))
                printf("[%5d] PAI: O meu filho terminou com %d...\n", pid, WEXITSTATUS(estado));
        }  
        else {
            printf("A sair...\n");
            continua = 0;
        }
    }
    exit(0);
}