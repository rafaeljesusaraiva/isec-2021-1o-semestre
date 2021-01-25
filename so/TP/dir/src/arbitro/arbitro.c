#include "arbitro.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // ./arbitro -t [tempo campeonato] -e [tempo espera]

    // (stor) export GAMEDIR="./dist/"
    // (stor, se executado em ./dist ) export GAMEDIR="./"
    // (stor) export MAXPLAYERS=25

    char tmp_txt[200];
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

    sprintf(tmp_txt, "FIFO aberto '%s'", FIFO_SRV);
    debug(tmp_txt, NULL, -1);

/*****************************************/
    // ^^^ - Inicialização do árbitro
    // vvv - Funcionamento do árbitro
/*****************************************/

    Jogadores *jogadores = NULL;
    int n_jogadoresCampeonato = 0;
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
            }else if (strcmp(cmd_t,"help") == 0 || strcmp(cmd_t,"h") == 0) {
                //mostra ajuda
                mostra_ajuda();
            }else if (strcmp(cmd_t,"players") == 0) {
                //lista jogadores em jogo
                lista_jogadores(jogadores);
            }
            
            else if (strcmp(cmd_t,"comeca") == 0) {
                //Comeca campeonato
                // definir timer
                // mandar msgs aos jogadores
            }
            
            else if (strcmp(cmd_t,"games") == 0){
                //lista de jogos
                lista_jogos(jogos);
            }else if(cmd_t[0] == 'g'){
                // ex: grui
                do {
                    printf("Jogo Novo (g_[jogo]):");
                    scanf("%s", tmp_txt);
                } while (existe_jogo(jogos, tmp_txt) == 0);

                fflush(stdout);
                fflush(stdin);

                mudaJogo_jogador(jogadores, pedido_cli.nome, tmp_txt);
                // debug("Copiar nova info para o pedido de envio", NULL, -1);
                // strcpy(pedido_cli.jogo, tmp_txt);
                // strcpy(pedido_cli.comando, "Novo jogo associado");
                // debug("Info copiada", NULL, -1);

                // sprintf(tmp_txt, "[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
                // debug(tmp_txt, NULL, -1);

                
                // debug("Aqui", NULL, -1);
                // if (envio == sizeof(Comm_cli)) {
                //     sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
                //     fdr = open(fifo, O_WRONLY);
                //     sprintf(tmp_txt, "nG%s", pedido_cli.jogo);
                //     envio = write(fdr, tmp_txt, sizeof(tmp_txt));
                //     close(fdr);
                // }
                // strcpy(pedido_cli.comando, "");
                
            }else if(cmd_t[0] == 'k'){
                // ex: krui ---> elimina o jogador rui 
                char *tmp_name = cmd_t;
                tmp_name++;     // remove K
                jogadores = remove_jogador(jogadores, tmp_name);
            }else if(cmd_t[0] == 's'){
                // ex: srui ---> suspende stdout jogo rui 
                
            }
            else if(cmd_t[0] == 'r'){
                // ex: srui ---> resume stdout jogo rui 
                
            } else {
                printf("Comando desconhecido, tente novamente.");
            }
		} 
        
        //NPIPES (Escrever nos clientes)
        // >> Recebe pedido do cliente
        else if (res > 0 && FD_ISSET(fd, &fds)) {

            debug("Recebi algo", NULL, -1);

            char respostaSimples [1024];

            // le pedido fifo
            envio = read(fd, &pedido_cli, sizeof(Comm_cli));
            debug("Recebi isto", &pedido_cli, envio);

            // PROCESSA O PEDIDO DO CLIENTE
            sprintf(tmp_txt, "Processa pedido");
            debug(tmp_txt, NULL, -1);
            int accao = processa_pedido(&pedido_cli, envio);

            sprintf(tmp_txt, "Escolher opcao");
            debug(tmp_txt, NULL, -1);
            // OPCAO - NOVO JOGADOR
            if (strcmp(pedido_cli.comando, "novoNome") == 0) {
                debug("Nova inscricao", NULL, -1);
                debug("A procurar se jogador ja existe", NULL, -1);
                // VERIFICA SE CLIENTE (NOME) JA EXISTE
                int existe = 0;
                if (procura_jogador(jogadores, pedido_cli.nome) == 1)
                    existe = 1;

                if (existe == 0) {
                    debug("Jogador novo!", NULL, -1);

                    // ATRIBUI JOGO RANDOM
                    int random_number = rand() % total_jogos(jogos) + 1;
                    strcpy(pedido_cli.jogo, nome_jogo(jogos, random_number));
                    sprintf(tmp_txt, "Jogo aleatorio obtido (%s)", pedido_cli.jogo);
                    debug(tmp_txt, NULL, -1);

                    // TERMINA E LIMPA PEDIDO
                    sprintf(tmp_txt, "Limpeza de pedido");
                    debug(tmp_txt, NULL, -1);
                    pedido_cli.fim = 0;
                    strcpy(pedido_cli.comando, "");
                    pedido_cli.pontuacao = 0;

                    // ADICIONA JOGADOR A LISTA || CRIA THREAD E PIPE PARA JOGAR
                    //      cliente <-> thread (jogo)
                    sprintf(tmp_txt, "A adicionar jogador e criar thread+fifo apropriados.");
                    debug(tmp_txt, NULL, -1);
                    jogadores = adiciona_jogador(jogadores, pedido_cli, &trinco);
                    strcpy(pedido_cli.comando, "recebido");
                } else {
                    sprintf(tmp_txt, "Jogador ja existe!");
                    debug(tmp_txt, NULL, -1);
                    pedido_cli.fim = -1;
                }
                
                // Enviar info ao cliente
                // interpretar
                printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
                sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &pedido_cli, sizeof(Comm_cli));
                close(fdr);
                debug("Enviei isto", &pedido_cli, envio);
                strcpy(pedido_cli.comando, "");
                continue;
            } 

            // OPCAO - MYGAME
            else if (strcmp(pedido_cli.comando, "#mygame") == 0) {
                sprintf(tmp_txt, "Escolheu mygame");
                debug(tmp_txt, NULL, -1);
                // RETORNAR NOME MYGAME
                sprintf(tmp_txt, "\nJogo Atual:  %s", obtem_jogoCliente(jogadores, pedido_cli.nome));

                // Enviar info ao cliente
                // interpretar
                printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);

                sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &tmp_txt, sizeof(tmp_txt));
                close(fdr);
                continue;
            }

            // OPCAO - JOGADOR A SAIR
            else if (strcmp(pedido_cli.comando, "#quit") == 0) {
                sprintf(tmp_txt, "Escolheu sair");
                debug(tmp_txt, NULL, -1);
                desativa_jogador(jogadores, pedido_cli.nome);
                
                // RETORNAR INFO (aceitar saida cliente)
                pedido_cli.fim = 1;
                sprintf(tmp_txt, "sair");
                // Enviar info ao cliente
                // interpretar
                printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
                sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &tmp_txt, sizeof(tmp_txt));
                close(fdr);

                sprintf(tmp_txt, "\n\nTotal de pontos: %d", pedido_cli.pontuacao);

                // Enviar info ao cliente
                // interpretar
                printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
                sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &tmp_txt, sizeof(tmp_txt));
                close(fdr);
                continue;
            } 

            // OPCAO - COMANDO INVALIDO
            else if (pedido_cli.comando[0] == '#') {
                debug("Escolheu comando invalido", NULL, -1);
                sprintf(tmp_txt, "Comando Invalido");
                printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
                sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
                fdr = open(fifo, O_WRONLY);
                envio = write(fdr, &tmp_txt, sizeof(tmp_txt));
                close(fdr);
                continue;
            }

            // OPCAO - TEXTO PARA JOGO
            else {
                // INPUT FIFO JOGO
                debug("Escolheu texto para jogo", NULL, -1);
                sprintf(tmp_txt, "Comando para jogo... (%s)", pedido_cli.comando);
                strcpy(pedido_cli.comando, tmp_txt);
                debug("Copiou texto para pedido", NULL, -1);
            }

            // Enviar info ao cliente
            // interpretar
            printf("[INFO] A devolver informacao ao cliente '%s'", pedido_cli.nome);
            sprintf(fifo, FIFO_THR_OUT, pedido_cli.pid);
            fdr = open(fifo, O_WRONLY);
            envio = write(fdr, &pedido_cli, sizeof(Comm_cli));
            close(fdr);
            debug("Enviei isto", &pedido_cli, envio);
            strcpy(pedido_cli.comando, "");
        }
        
	} while (1);
    pthread_mutex_destroy(&trinco);
    close(fd);
	unlink(FIFO_SRV);

	return FIM_BOM;
}