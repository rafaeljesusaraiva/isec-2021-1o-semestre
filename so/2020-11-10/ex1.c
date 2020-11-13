#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int num;

void mostra(int s) {
    printf("\nAcorda!! (recebi o sinal %d na interacao %d)\n", s, num);
    fflush(stdout);
    exit(33);
}

int main(int argc, char *argv[]) {
    int i;
    char str[40];

    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1, mostra);     // tratar o sinal
    signal(SIGALRM, mostra);    // tratar o sinal
    printf("O meu PID e %d...\n", getpid());
    printf("Vou dormir...\n");
    // do {
    //     pause();        // espera por sinal
    // } while(1);

    do {
        printf("Nome (%d)? ", ++num);
        fflush(stdout);
        scanf("%s", str);
        alarm(0);
        printf("Ola");
        for (i=0; i<5; i++) {
            printf("a");
            fflush(stdout);
            sleep(1);
        }
        printf(" %s!!!\n", str);
    } while(strcmp(str, "sair") != 0);

    exit(0);
}