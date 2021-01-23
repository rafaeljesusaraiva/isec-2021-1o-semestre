#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

//
// ADIVINHA O NÚMERO
//

int pontos=0;

void sair(int s) {
    printf("\n\n\tOBTEVE %d PONTOS!\n", pontos);
    exit(pontos);
}

int main() {
    srand(time(NULL)); // Iniciar variabilidade para limMax e limMin
    int limMax, limMin, num, input;

    signal(SIGUSR1, sair); //   Quando o sinal for detetado executa ...

    do {
        // Numero aleatório com limites [lower, upper] (expressão)
        // num = (rand() % (upper - lower + 1)) + lower; 
        limMax = (rand() % (50 - 35 + 1)) + 35; // Limite de [35, 50]
        limMin = (rand() % 25) + 1;             // Limite de [1, 25]
        num = (rand() % (limMax - limMin + 1)) + limMin;

        // saber pid
        // printf("PID: %d\n", getpid());

        printf("Adivinhe o número entre %d e %d (%d): ", limMin, limMax, num);
        scanf("%d", &input);
        if (input != num)
            printf("\tResposta Incorreta, o número a adivinhar era %d.\n", num);
            // Dar pontos de acordo com a proximidade da adivinha ?
        else {
            printf("\tResposta Correta! Ganhou 10 pontos!\n");
            pontos += 10;
        }
	} while (1);

	// printf("OBTEVE %d PONTOS!\n", pontos);
    // return pontos;
    exit(pontos);
}