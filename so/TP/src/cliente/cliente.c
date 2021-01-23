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

    // Preparacao dos pipes
    char fifo_out[90], fifo_in[90];
    sprintf(fifo_out, FIFO_THR_OUT, pedido_cli.pid);
    sprintf(fifo_in, FIFO_THR_IN, pedido_cli.pid);
    int pipe_out = open( fifo_out, O_RDONLY );  // obtem output do jogo
    int pipe_in = open( fifo_in, O_WRONLY );    // envia input p/ jogo
    int res, fd_t;
    char *outputJogo;
    fd_set fds;
    struct timeval tempo;

/*****************************************/
    // ^^^ - Inicialização do cliente
    // vvv - Funcionamento do cliente
/*****************************************/

    do { 
        // Imprimir info do jogo
        pontuacao = pedido_cli.pontuacao;

        // scanf
        printf("\nCOMANDO: ");
        fflush(stdout);

        FD_ZERO(&fds);
        //Toma atençao ao teclado->0
        FD_SET(0, &fds);
        //toma atençao ao pipe do jogo
        FD_SET(pipe_out, &fds);
        tempo.tv_sec = 10;
        tempo.tv_usec = 0;

        res = select(fd+1, &fds, NULL, NULL, &tempo);

        if (res > 0 && FD_ISSET(0, &fds)) {
            scanf("%s", comando_t);

            // CASO SEJA COMANDO
            if (comando_t[0] == '#') {
                if (strcmp("#mygame", comando_t) == 0)
                    printf("JOGO ATUAL: %s\n", pedido_cli.jogo);

                else if (strcmp("#quit", comando_t) == 0) {
                    // desiste campeonato
                    pedido_cli.fim = 1;
                    strcpy(pedido_cli.comando, "sair");
                    envio = write(fd, &pedido_cli, sizeof(Comm_cli));
                    break;
                }

                else {
                    printf("Comando Invalido..\n");
                    continue;
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
            } else {
                // CASO SEJA INPUT P/ JOGO
                #ifdef DEBUG
                    printf("Input nao local (nao comeca por #)\n");
                    printf("A enviar para o fifo\n");
                #endif
                envio = write(pipe_in, comando_t, sizeof(comando_t));
                printf("nbytes escritos %d", envio);
            }
        }

        else if (res > 0 && FD_ISSET(fd, &fds)) {
            envio = read(pipe_out, outputJogo, 100);
                if (envio > 0)
                    printf("%s\n", outputJogo);
        }

    } while (pedido_cli.fim != 1);

    close(pipe_in);
    // close(fd);
    unlink(fifo);
    return pontuacao;
}