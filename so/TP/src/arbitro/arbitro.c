#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "constantes.h"
#include "../estruturas.h"

void print_commcli(Comm_cli *temp, int size) {
    printf("[DEBUG] > pid: %d", temp->pid);
    printf("[DEBUG] > nome: %s", temp->nome);
    printf("[DEBUG] > jogo: %s", temp->jogo);
    printf("[DEBUG] > pontuacao: %d", temp->pontuacao);
    printf("[DEBUG] > comando: %s", temp->comando);
    printf("[DEBUG] > fim: %d", temp->fim);
    printf("[DEBUG] > Tamanho Enviado: %d", size);
}

int main(int argc, char *argv[]) {

    // ./arbitro -t [tempo campeonato] -e [tempo espera]

    // (stor) export GAMEDIR="dist/"
    // (stor) export MAXPLAYERS=25

    // OBTER VARIAVEIS
    char *env_GAMEDIR = getenv("GAMEDIR");
    char *env_MAXPLAYERS = getenv("MAXPLAYERS");

    //Verificaçao das variaveis de ambiente
    if (env_MAXPLAYERS == NULL) {
        printf("[Erro] Falta variável ambiente MAXPLAYERS\n");
        return ERRO_FALTA_ENV;
    }
    if (env_GAMEDIR == NULL) {
        // definir diretoria atual como default;
        printf("[AVISO] Falta variável ambiente GAMEDIR.\n");
        printf("[AVISO] Diretoria base dos jogos definida para a pasta base do arbitro.\n");
        env_GAMEDIR = "./";
    }

    // Verificar se env_MAXPLAYERS <= 30 e env_MAXPLAYERS >= 2
    // Limite máx -> MAXDEFINEDPLAYERS
    int int_MAXPLAYERS = atoi(env_MAXPLAYERS);
    if (int_MAXPLAYERS >= MAXDEFINEDPLAYERS || int_MAXPLAYERS <= MINPLAYERS) {
        printf("[Erro] Variavel players fora de limites\n");
        return ERRO_MAXPLAYERS_EXCEDIDO;
    }

	// OBTER ARGUMENTOS
    int opt, conft = 0, confe = 0;
    while((opt = getopt(argc, argv, "t:e:")) != -1) {  
        switch(opt) {   
            case 't':
                printf("tempo campeonato (opcao %c): %s\n", opt, optarg);
                conft = 1; 
                break;  
            case 'e':
                printf("tempo espera: %s\n", optarg);
                confe = 1;
                break;
            case '?':  
                printf("opcao desconhecida (%c): %c\n", opt, optopt); 
                break;  
        }  
    }
    if (conft == 0 || confe == 0) {
        printf("[ERRO] Inicializacao incorreta. (./arbitro -t [tempo campeonato] -e [tempo espera])\n");
        return ERRO_ARG;
    }

    //criar o named pipe do arbitro
	if (access(FIFO_SRV, F_OK) !=  0) {
        mkfifo(FIFO_SRV,0600);
#ifdef DEBUG
        printf("[DEBUG] FIFO criado servidor\n");
#endif
    } else {
        printf("[ERRO] FIFO já existente, instância ARBITRO ligada?\n");
        return ERRO_FIFO_EXISTE;
    }

    int fd, fdr, envio;
    fd_set fds;
    char cmd_t[30], fifo[90];

    fd = open(FIFO_SRV, O_RDWR);
#ifdef DEBUG
        printf("[DEBUG] FIFO aberto '%s'\n", FIFO_SRV);
#endif

    // ^^^ - Inicialização do árbitro
    // vvv - Funcionamento do árbitro
    Comm_cli pedido_cli;

    do {
		printf("COMANDO (ARBITRO): ");
		fflush(stdout);
        
        FD_ZERO(&fds);
        FD_SET(0, &fds);
        FD_SET(fd, &fds);
        // tempo???
        // if (res == 0) { printf("Nao ha dados"); } else
        if (/* res > 0 && */FD_ISSET(0, &fds)) {
            // ler comandos admin
            scanf("%s", cmd_t);
            if (strcmp(cmd_t, "exit") == 0)
                pedido_cli.fim = 1;
        } else if (/* res > 0 && */FD_ISSET(fd, &fds)) {
            // le pedido fifo
            envio = read(fd, &pedido_cli, sizeof(Comm_cli));
#ifdef DEBUG
            printf("[DEBUG] Recebi isto: \n");
            print_commcli(&pedido_cli, envio);
#endif
            if (envio == sizeof(Comm_cli)) {
                // interpretar
                sprintf(fifo, FIFO_CLI, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &pedido_cli, sizeof(Comm_cli));
                close(fdr);
#ifdef DEBUG
            printf("[DEBUG] Enviei isto: \n");
            print_commcli(&pedido_cli, envio);
#endif
            }
        }
        

	} while (pedido_cli.fim != 1);
    close(fd);
	unlink(FIFO_SRV);

	return FIM_BOM;
}