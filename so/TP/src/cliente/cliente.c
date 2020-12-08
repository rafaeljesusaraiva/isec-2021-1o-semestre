#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "constantes.h"
#include "../estruturas.h"

int pontuacao;
char fifo[90];

void print_commcli(Comm_cli *temp, int size) {
    printf("[DEBUG] > pid: %d", temp->pid);
    printf("\n[DEBUG] > nome: %s", temp->nome);
    printf("\n[DEBUG] > jogo: %s", temp->jogo);
    printf("\n[DEBUG] > pontuacao: %d", temp->pontuacao);
    printf("\n[DEBUG] > comando: %s", temp->comando);
    printf("\n[DEBUG] > fim: %d", temp->fim);
    printf("\n[DEBUG] > Tamanho Enviado: %d\n", size);
}

void terminadoJogo() {
    printf("\nJogo terminado pelo árbitro. Teve pontuação de %d.", pontuacao);
    unlink(fifo);
    exit(pontuacao);
}

void sairJogo() {
    unlink(fifo);
    exit(pontuacao);
}

int main() {

    pontuacao = 0;

	char strcli[40], nome_t[30];
    int fd, fdr;
    char comando_t[30];
    // envio = tamanho do que foi enviado
    int envio;
	Comm_cli pedido_cli;

    // struct sigaction act;
    // act.sa_handler = sairJogo;
    // act.sa_flags = SA_RESTART;
    // sigaction(SIGINT, &act, NULL);
    signal(SIGINT, sairJogo);
    signal(SIGUSR1, terminadoJogo);

	if ( access(FIFO_SRV, F_OK) != 0) {
        fprintf(stderr, "[ERRO] Arbitro nao inicializado!\n");
        exit(FIM_NOARBITRO);
    }

    pedido_cli.pid = getpid();
    pedido_cli.fim = -1;
	sprintf(fifo, FIFO_CLI, pedido_cli.pid);
    //CRIEI O FIFO
    mkfifo(fifo, 0600);
#ifdef DEBUG
    printf("[DEBUG] FIFO criado '%s'\n", fifo);
#endif
    // Abri o fifo apenas para escrever 
    fd = open(FIFO_SRV, O_WRONLY);
#ifdef DEBUG
    printf("[DEBUG] FIFO servidor aberto '%s'\n", FIFO_SRV);
#endif

    //obter a identificacao do utilizador (nome)
    int loop_t = 0;
    do {
        if (loop_t == 1)
            printf("(Nome já existente, tente outro...\n)");
        loop_t = 1;
        printf("Nome: ");
        fflush(stdout);
        scanf("%s", nome_t);
        strcpy(pedido_cli.nome, nome_t);
        strcpy(pedido_cli.comando, "novoNome");

        // enviar info
        envio = write(fd, &pedido_cli, sizeof(Comm_cli));
#ifdef DEBUG
        print_commcli(&pedido_cli, envio);
#endif
        // recebe feedback arbitro
        fdr = open(fifo, O_RDONLY);
        envio = read(fdr, &pedido_cli, sizeof(Comm_cli));
        close(fdr);
#ifdef DEBUG
        print_commcli(&pedido_cli, envio);
#endif
    } while(pedido_cli.fim == -1);

    do { 
        // Imprimir info do jogo
        pontuacao = pedido_cli.pontuacao;

        // scanf
        printf("COMANDO: ");
        fflush(stdout);
        scanf("%s", comando_t);

        if (strcmp("#mygame", comando_t) == 0) {
            printf("JOGO ATUAL: %s\n", pedido_cli.jogo);
        } else {
            // decide
            if (strcmp("#quit", comando_t) == 0) {
                // desiste campeonato
                pedido_cli.fim = 1;
                strcpy(pedido_cli.comando, "sair");
                envio = write(fd, &pedido_cli, sizeof(Comm_cli));
                break;
            } else {
                strcpy(pedido_cli.comando, comando_t);
            }
            // manda
            envio = write(fd, &pedido_cli, sizeof(Comm_cli));
#ifdef DEBUG
            print_commcli(&pedido_cli, envio);
#endif
            // recebe feedback arbitro
            fdr = open(fifo, O_RDONLY);
            envio = read(fdr, &pedido_cli, sizeof(Comm_cli));
            close(fdr);
#ifdef DEBUG
            print_commcli(&pedido_cli, envio);
#endif
            if (strcmp(pedido_cli.comando, "encerra") == 0)
                pedido_cli.fim = 1;
        }
    } while (pedido_cli.fim != 1);

    // close(fd);
    unlink(fifo);
    return pontuacao;
}