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

    signal(SIGALRM, mostra);    // tratar o sinal
    printf("O meu PID e %d...\n", getpid());
    do {
        printf("Nome (%d)? ", ++num);
        fflush(stdout);
        alarm(10);
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