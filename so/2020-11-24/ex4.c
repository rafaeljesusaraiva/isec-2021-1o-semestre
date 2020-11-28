#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    char str[40];
    int continua=1, pid, res, estado, n;
    int canal[2];

    pid = getpid();
    while (continua) {
        printf("[%5d] COMANDO: ", pid);
        fflush(stdout);
        scanf("%s", str);
        if (strcmp(str, "sair") != 0) {
    pipe(canal);
            res = fork();
            if (res == 0) {
                pid = getpid();
                printf("[%5d] FILHO: Sou o filho..", pid);
        close(canal[0]);
        close(1);
        dup(canal[1]); /* dup2(canal[1], 1); */
        close(canal[1]);
                execl(str, str, NULL);
                printf("[%5d] FILHO: Erro a executar cmd!", pid);
                exit(7);
            }
            printf("[%5d] PAI: Criei o filho PID=%d", pid, res);
    close(canal[1]);
    while ((n = read(canal[0], str, 39)) != 0){ // =0 => EOF
        str[n] = '\0';
        printf("[%5d] PAI: Recebi... '%s'\n", pid, str);
    }
    close(canal[0]);
            wait(&estado);
            if (WIFEXITED(estado)) {
                printf("[%5d] PAI: O meu filho terminou com %d!\n", pid, WEXITSTATUS(estado));
            }
        } else {
            continua = 0;
        }
    }
    exit(0);
}