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
    printf("\n[DEBUG] > Tamanho Enviado: %d", size);
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
    char comando_t[30];
    // envio = tamanho do que foi enviado
    int envio;
	Comm_cli pedido_cli;

    // struct sigaction act;
    // act.sa_handler = sairJogo;
    // act.sa_flags = SA_RESTART;
    // sigaction(SIGINT, &act, NULL);

    // ATIVA RESPOSTA AOS SINAIS PARA RECEBER
    signal(SIGINT, sairJogo);
    signal(SIGUSR1, terminadoJogo);

    // VERIFICA SE ARBITRO ESTA A FUNCIONAR
	if ( access(FIFO_SRV, F_OK) != 0) {
        fprintf(stderr, "[ERRO] Arbitro nao inicializado!\n");
        exit(FIM_NOARBITRO);
    }

    // PREENCHE PEDIDO INICIAL
    pedido_cli.pid = getpid();
    pedido_cli.fim = -1;


    int fd_in, fd_out;
	
    //CRIEI O FIFO
    #ifdef DEBUG
        printf("A criar fifo escrita:\n");
    #endif
    sprintf(fifo, FIFO_THR_IN, pedido_cli.pid);
    mkfifo(fifo, 0600);
    fd_in = open(fifo, O_WRONLY | O_NONBLOCK);

    #ifdef DEBUG
        printf("A criar fifo leitura:\n");
    #endif
    sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
    mkfifo(fifo, 0600);
    fd_out = open(fifo, O_RDONLY | O_NONBLOCK);

    // FAZER SETUP CLIENTE <-> SERVIDOR

    // Flag nome errado
    int loop_t = 0;
    do {
        if (loop_t == 1)
            printf("Nome já existente, tente outro...\n");
        loop_t = 1;
        printf("Nome: ");
        fflush(stdout);
        scanf("%s", nome_t);
        strcpy(pedido_cli.nome, nome_t);
        strcpy(pedido_cli.comando, "novoNome");

        // enviar info
        int main = open(FIFO_SRV, O_WRONLY);
        envio = write(main, &pedido_cli, sizeof(Comm_cli));
        close(main);

        do {
            #ifdef DEBUG
                printf("A tentar ler:\n");
            #endif
            envio = read(fd_out, &pedido_cli, sizeof(Comm_cli));
            sleep(1);
        } while(strcmp(pedido_cli.comando, "recebido") != 0);

    } while(pedido_cli.fim == -1);

    int res;
    fd_set fds;
    struct timeval tempo;
    char outputJogo[200];

/*****************************************/
    // ^^^ - Inicialização do cliente
    // vvv - Funcionamento do cliente
/*****************************************/

    #ifdef DEBUG
        printf("Comeca loop cliente\n");
    #endif

    do { 
        printf("\nCOMANDO: ");
        fflush(stdout);

        FD_ZERO(&fds);
        FD_SET(0, &fds);    // VER TECLADO
        FD_SET(fd_out, &fds);   // VER FIFO

        // DEFINIR TIMEOUTS
        tempo.tv_sec = 10;
        tempo.tv_usec = 0;

        // DEFINIR SELETOR DE INPUT
        // res = select(fd_out+1, &fds, NULL, NULL, &tempo);
        res = select(fd_out+1, &fds, NULL, NULL, &tempo);
        
        // HA ERRO
        if (res == -1)
            printf("Erro fifos");

        // NAO HA INPUT
        else if (!res)
            continue;

        // INPUT CLIENTE
        else if (res > 0 && FD_ISSET(0, &fds)) {
            // OBTER COMANDO
            scanf("%s", comando_t);
            // COPIAR COMANDO PARA ENVIO
            if (comando_t[0] == '#') {
                strcpy(pedido_cli.comando, comando_t);
                int mainPipe = open(FIFO_SRV, O_WRONLY);
                envio = write(mainPipe, &pedido_cli, sizeof(Comm_cli));
                close(mainPipe);

            } else {
                // ENVIO DE DADOS PARA ARBITRO
                envio = write(fd_in, &comando_t, sizeof(comando_t));
                #ifdef DEBUG
                    printf("Enviado:\n");
                    print_commcli(&pedido_cli, envio);
                #endif
            }
        }
        // recebe de fora
        else if (res > 0 && FD_ISSET(fd_out, &fds)) {
            #ifdef DEBUG
                printf("Recebe de fora\n");
            #endif
            envio = read(fd_out, &outputJogo, sizeof(outputJogo));
            #ifdef DEBUG
                printf("Leu o fifo\n");
            #endif
            if (strcmp(outputJogo, "sair") == 0) {
                pedido_cli.fim = 1;
                printf("%s", outputJogo);
                envio = read(fd_out, &outputJogo, sizeof(outputJogo));
                printf("%s", outputJogo);
            } else {
                #ifdef DEBUG
                    printf("Verificou o fifo\n");
                #endif
                printf("%s", outputJogo);
            }
            sleep(1);
        }

    } while (pedido_cli.fim != 1);

    close(fd_in);
    close(fd_out);
    unlink(fifo);
    return pontuacao;
}