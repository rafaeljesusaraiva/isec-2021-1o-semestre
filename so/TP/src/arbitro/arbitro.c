#include "arbitro.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // ./arbitro -t [tempo campeonato] -e [tempo espera]

    // (stor) export GAMEDIR="./dist/"
    // (stor, se executado em ./dist ) export GAMEDIR="./"
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
    int int_MAXPLAYERS = (env_MAXPLAYERS != NULL) ? atoi(env_MAXPLAYERS) : -1;
    check_envVariables(env_GAMEDIR, env_MAXPLAYERS, int_MAXPLAYERS);

	// OBTER ARGUMENTOS
    int tmp_Campeonato = 0, tmp_Espera = 0;
    get_argumentos(argc, argv, &tmp_Campeonato, &tmp_Espera);
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
    pthread_mutex_t trinco;

    Jogos *jogos = obtem_jogos(env_GAMEDIR);

    pthread_mutex_init(&trinco, NULL);

    do {
        printf("\n[ARBITRO]> ");
		fflush(stdout);
        
        FD_ZERO(&fds);
        //Toma atençao ao teclado->0
        FD_SET(0, &fds);
        //toma atençao do npipe->fd
        FD_SET(fd, &fds);
        tempo.tv_sec = tmp_Espera;
        tempo.tv_usec = 0;
        // printf("select begin\n");
        res = select(fd+1, &fds, NULL, NULL, &tempo);
        // printf("select end\n");
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
            }else if (strcmp(cmd_t,"help") == 0 || strcmp(cmd_t,"h") == 0) {
                //mostra ajuda
                mostra_ajuda();
            }else if (strcmp(cmd_t,"players") == 0) {
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
                printf("Comando desconhecido, tente novamente. \n");
            }
		} 
        
        //NPIPES (Escrever nos clientes)
        // >> Recebe pedido do cliente
        else if (res > 0 && FD_ISSET(fd, &fds)) {

            // le pedido fifo
            envio = read(fd, &pedido_cli, sizeof(Comm_cli));
            debug("Recebi isto", &pedido_cli, envio);

            // PROCESSA O PEDIDO DO CLIENTE
            int accao = processa_pedido(&pedido_cli, envio);

            // OPCAO - NOVO JOGADOR
            if (strcmp(pedido_cli.comando, "novoNome") == 0) {
                // VERIFICA SE CLIENTE (NOME) JA EXISTE
                if (procura_jogador(jogadores, pedido_cli.nome) == 1)
                    break;

                // ATRIBUI JOGO RANDOM
                int random_number = rand() % total_jogos(jogos) + 1;
                strcpy(pedido_cli.jogo, nome_jogo(jogos, random_number));

                // TERMINA E LIMPA PEDIDO
                pedido_cli.fim = 0;
                strcpy(pedido_cli.comando, "");

                // ADICIONA JOGADOR A LISTA
                // CRIA THREAD E PIPE PARA JOGAR
                //      cliente <-> thread (jogo)
                jogadores = adiciona_jogador(jogadores, pedido_cli, &trinco);
            } 

            // OPCAO - JOGADOR A SAIR
            else if (strcmp(pedido_cli.comando, "sair") == 0) {
                desativa_jogador(jogadores, pedido_cli.nome);
                continue;
            } 

            // OPCAO - PEDIDO INVALIDO
            else {
                pedido_cli.fim = 0;
                strcpy(pedido_cli.comando, "invalido");
            }

            // Enviar info ao cliente
            if (envio == sizeof(Comm_cli)) {
                // interpretar
                printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
                sprintf(fifo, FIFO_CLI, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &pedido_cli, sizeof(Comm_cli));
                close(fdr);
                debug("Enviei isto", &pedido_cli, envio);
            }
        }
	} while (1);
    pthread_mutex_destroy(&trinco);
    close(fd);
	unlink(FIFO_SRV);

	return FIM_BOM;
}