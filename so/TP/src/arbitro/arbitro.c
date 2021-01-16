#include "arbitro.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // ./arbitro -t [tempo campeonato] -e [tempo espera]

    // (stor) export GAMEDIR="./dist/"
    // (stor) export MAXPLAYERS=25

    char tmp_txt[250];
    // sprintf(tmp_txt, "<texto>", vars)
    // debug(tmp_txt, <estrutura Comm_cli>, tamanho);
    // tamanho -1 e estrutura a NULL para só imprimir texto DEBUG
    //          debug(tmp_txt, NULL, -1)

    // OBTER VARIAVEIS
    char *env_GAMEDIR = getenv("GAMEDIR");
    char *env_MAXPLAYERS = getenv("MAXPLAYERS");
    // Verificar se env_MAXPLAYERS <= 30 e env_MAXPLAYERS >= 2
    // Limite máx -> MAXDEFINEDPLAYERS
    int int_MAXPLAYERS = atoi(env_MAXPLAYERS);

    check_envVariables(env_GAMEDIR, env_MAXPLAYERS, int_MAXPLAYERS);


	// OBTER ARGUMENTOS
    int tmp_Campeonato = 0, tmp_Espera = 0;
    int opt;
    while((opt = getopt(argc, argv, "t:e:")) != -1) {  
        switch(opt) {   
            case 't':
                sprintf(tmp_txt, "tempo campeonato (opcao %c): %s\n", opt, optarg);
                debug(tmp_txt, NULL, -1);
                tmp_Campeonato = atoi(optarg);
                break;  
            case 'e':
                sprintf(tmp_txt, "tempo espera: %s\n", optarg);
                debug(tmp_txt, NULL, -1);
                tmp_Espera = atoi(optarg);
                break;
            case '?':  
                printf("Opcao desconhecida (%c): %c\n", opt, optopt); 
                break;  
        }  
    }
    check_argumentos(tmp_Campeonato, tmp_Espera);


    //criar o named pipe do arbitro
	if (access(FIFO_SRV, F_OK) !=  0) {
        mkfifo(FIFO_SRV, 0600);
        debug("FIFO criado servidor", NULL, -1);
    } else {
        printf("[ERRO] FIFO já existente, instância ARBITRO ligada?\n");
        return ERRO_FIFO_EXISTE;
    }

    int fd, fdr, envio, res, accao;
    fd_set fds;
    char cmd_t[30], fifo[90];

    fd = open(FIFO_SRV, O_RDWR);

    sprintf(tmp_txt, "FIFO aberto '%s'\n", FIFO_SRV);
    debug(tmp_txt, NULL, -1);

/*****************************************/
    // ^^^ - Inicialização do árbitro
    // vvv - Funcionamento do árbitro
/*****************************************/

    Jogadores *jogadores = NULL;
    Comm_cli pedido_cli;
    struct timeval tempo;

    Jogos *jogos = obtem_jogos(env_GAMEDIR);

    do {
		printf("\nCOMANDO (ARBITRO): ");
		fflush(stdout);
        
        FD_ZERO(&fds);
        //Toma atençao ao teclado->0
        FD_SET(0, &fds);
        //toma atençao do npipe->fd
        FD_SET(fd, &fds);
        tempo.tv_sec = tmp_Espera;
        tempo.tv_usec = 0;
        res = select(fd+1, &fds, NULL, NULL, &tempo);

        // if (res == 0) { 
        //     printf("Nao ha dados de nenhuma das fontes!!\n"); 
        // } else
        //TECLADO (Escrever no arbitro)
        if (res > 0 && FD_ISSET(0, &fds)) {
            // ler comandos admin
            scanf("%s", cmd_t);
			// printf("Recebi o comando %s!!!\n", cmd_t);
			if (strcmp(cmd_t, "exit") == 0) {
                termina_jogos(jogadores);
                break;
            }	
            else if (strcmp(cmd_t,"players") == 0) {
                //lista jogadores em jogo
                lista_jogadores(jogadores);
            }else if (strcmp(cmd_t,"games") == 0){
                //lista de jogos
                lista_jogos(jogos);
            }else if(cmd_t[0] == 'k'){
                // ex: krui ---> elimina o jogador rui 
                char *tmp_name = cmd_t;
                tmp_name++;     // remove K
                jogadores = remove_jogador(jogadores, tmp_name);
            } else {
                printf("COMANDO (ARBITRO) desconhecido!!!\n");
                printf("\nInsira denovo o COMANDO (ARBITRO):");
                scanf("%s", cmd_t);
                // printf("Recebi o comando %s!!!\n", cmd_t);
            }
		} 
        
        //NPIPES (Escrever nos clientes)
        else if (res > 0 && FD_ISSET(fd, &fds)) {
            // le pedido fifo
            envio = read(fd, &pedido_cli, sizeof(Comm_cli));
            debug("Recebi isto", &pedido_cli, envio);
            int accao = processa_pedido(&pedido_cli, envio);
            switch (accao) {
                case -1:
                    desativa_jogador(jogadores, pedido_cli.nome);
                    continue;
                    break;
                case 0:
                    pedido_cli.fim = 0;
                    strcpy(pedido_cli.comando, "invalido");
                    break;
                case 1:
                    if (procura_jogador(jogadores, pedido_cli.nome) == 1)
                        break;
                    // atribuicao de jogo (aleatorio)
                    int max_jogos = total_jogos(jogos);
                    int random_number = rand() % max_jogos + 1;
                    strcpy(pedido_cli.jogo, nome_jogo(jogos, random_number));
                    pedido_cli.fim = 0;
                    strcpy(pedido_cli.comando, "");
                    jogadores = adiciona_jogador(jogadores, pedido_cli);
                    break;
            }
            if (envio == sizeof(Comm_cli)) {
                // interpretar
                sprintf(fifo, FIFO_CLI, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &pedido_cli, sizeof(Comm_cli));
                close(fdr);
                debug("Enviei isto", &pedido_cli, envio);
            }
        }
	} while (1);
    close(fd);
	unlink(FIFO_SRV);

	return FIM_BOM;
}