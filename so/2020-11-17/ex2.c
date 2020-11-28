#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

int nerradas = 0, ncertas = 0, tempo = 10;

void mostra(int s) {
    printf("TIMEOUT!! (Sinal = %d)\n", s);
    nerradas++;
}

void nova(int s, siginfo_t *info, void *context) {
    printf("TIMEOUT!! (Sinal = %d, PID = %d, Valor = %d)\n", s, info->si_pid, info->si_value);
    // So conto se foi enviado por mim (0)
    if (info->si_pid == 0)
        nerradas++;
}

int main(int argc, char *argv[]) {
    int i, n, res;
    char str[40];

#if 0
    // signal(SIGALRM, mostra);    // tratar o sinal
    struct sigaction act;
    act.sa_handler = mostra;
    act.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &act, NULL);
#else 
    struct sigaction act;
    act.sa_handler = nova;
    act.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &act, NULL);
#endif

    srand((unsigned int) time(NULL));    
    printf("O meu PID e %d...\n", getpid());
    do {
        int num1 = rand() % 101;
        int num2 = rand() % 101;
        printf("Tem %d segundos...\n", tempo);
        printf("%d + %d?\n", num1, num2);
        alarm(tempo);
        n = scanf("%d", &res);
        alarm(0);
        
        printf("ERROU!!!\n");
    } while(nerradas < 3);

    exit(0);
}