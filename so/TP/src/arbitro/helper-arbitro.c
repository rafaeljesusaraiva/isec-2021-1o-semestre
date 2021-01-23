#include "arbitro.h"

void print_commcli(Comm_cli *temp, int size) {
    printf("\n\t> pid: %d", temp->pid);
    printf("\n\t> nome: %s", temp->nome);
    printf("\n\t> jogo: %s", temp->jogo);
    printf("\n\t> pontuacao: %d", temp->pontuacao);
    printf("\n\t> comando: %s", temp->comando);
    printf("\n\t> fim: %d", temp->fim);
    printf("\n\t> Tamanho Enviado: %d\n", size);
}

void debug(char *texto, Comm_cli *temp, int size) {
#ifdef DEBUG
    printf("[DEBUG] %s\n", texto);
    if (temp != NULL && size != -1) {
        printf("[DEBUG] Info estrutura Com_cli");
        print_commcli(temp, size);
    }
#endif
}

void check_envVariables(char *gamedir, char *maxPlayers, int int_MAXPLAYERS) {
    //Verificaçao das variaveis de ambiente
    if (maxPlayers == NULL) {
        printf("[Erro] Falta variável ambiente MAXPLAYERS\n");
        exit(ERRO_FALTA_ENV);
    }
#ifdef DEBUG
        printf("[DEBUG] MAXPLAYERS: %s\n", maxPlayers);
#endif
    if (gamedir == NULL) {
        // definir diretoria atual como default;
        printf("\n[AVISO] Falta variável ambiente GAMEDIR.\n");
        printf("\n[AVISO] Diretoria base dos jogos definida para a pasta base do arbitro.\n");
        gamedir = "./";
    }
#ifdef DEBUG
        printf("[DEBUG] GAMEDIR: %s\n", gamedir);
#endif
    if (int_MAXPLAYERS >= MAXDEFINEDPLAYERS || int_MAXPLAYERS <= MINPLAYERS) {
        printf("[Erro] Variavel players fora de limites\n");
        exit(ERRO_MAXPLAYERS_EXCEDIDO);
    }
}

void get_argumentos(int argc, char *argv[], int *tmp_Campeonato, int *tmp_Espera) {
    char tmp_txt[250];
    int opt;
    while((opt = getopt(argc, argv, "t:e:")) != -1) {  
        switch(opt) {   
            case 't':
                sprintf(tmp_txt, "tempo campeonato (opcao %c): %s\n", opt, optarg);
                debug(tmp_txt, NULL, -1);
                *tmp_Campeonato = atoi(optarg);
                break;  
            case 'e':
                sprintf(tmp_txt, "tempo espera: %s\n", optarg);
                debug(tmp_txt, NULL, -1);
                *tmp_Espera = atoi(optarg);
                break;
            case '?':  
                printf("Opcao desconhecida (%c): %c\n", opt, optopt); 
                break;  
        }  
    }
}

void check_argumentos(int t_campeonato, int t_espera) {
    if (t_campeonato == 0 || t_espera == 0) {
        printf("[ERRO] Inicializacao incorreta. (./arbitro -t [tempo campeonato] -e [tempo espera])\n");
        exit(ERRO_ARG);
    }
}

int total_jogos(Jogos *lista) {
    Jogos *tmp_lista = lista;
    int total = 0;
    while (lista != NULL) {
        total++;
        lista = tmp_lista->seg;
    }
    lista = tmp_lista;
    return total;
}

void lista_jogos(Jogos *lista) {
    Jogos *tmp_lista = lista;
    printf("Lista Jogos:\n");
    while (lista != NULL) {
        printf("  > %s \n", lista->nome);
        lista = tmp_lista->seg;
    }
    lista = tmp_lista;
}

char *nome_jogo(Jogos *lista, int num) {
    Jogos *tmp_lista = lista;
    int pos = 1;
    while (lista != NULL) {
        if (pos == num)
            return lista->nome;
        pos++;
        lista = tmp_lista->seg;
    }
    lista = tmp_lista;
    return NULL;
}

Jogos *obtem_jogos(char env_GAMEDIR[]) {
    Jogos *lista, *tmp_lista, *novo;
    lista = (Jogos *) malloc(sizeof(Jogos));
    if (lista == NULL) { // nao alocou
        printf("[ERRO] Alocacao de memoria inicial falhou\n");
        return lista;
    }
    tmp_lista = lista; //  guarda inicio do endereço da lista
    int total = 0; // total jogos

    DIR *d;
    struct dirent *dir;
    d = opendir(env_GAMEDIR);
    // char tempName[30];
    // printf("A pesquisar jogos\n");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            // printf("%s\n", dir->d_name);
            if ((dir->d_name)[0] == 'g' && (dir->d_name)[1] == '_') {
                if (total == 0) {
                    // printf("[AVISO] Jogo encontrado: %s\n", dir->d_name);
                    strncpy(lista->nome, dir->d_name, sizeof(lista->nome));
                    lista->seg = NULL;
                    total++;
                } else {
                    novo = (Jogos *) malloc(sizeof(Jogos));
                    if (novo == NULL) { // nao alocou
                        printf("[ERRO] Alocacao de memoria falhou para %s\n", dir->d_name);
                        closedir(d);
                        return tmp_lista;
                    }
                    strncpy(novo->nome, dir->d_name, sizeof(novo->nome));
                    total++;

                    lista->seg = novo;
                    lista = lista->seg;
                    lista->seg = NULL;
                }
            }
        }
        closedir(d);
    }
    if (total == 0) printf("[AVISO] Nenhum jogo na diretoria %s\n", env_GAMEDIR);
    return tmp_lista;
}

void mostra_ajuda() {
    printf("###### AJUDA ######\n");
    printf("   > players\n");
    printf("\tMostra jogadores inscritos com o arbitro.\n");
    printf("   > games\n");
    printf("\tMostra jogos disponiveis.\n");
    printf("   > k[player]\n");
    printf("\tRemove o jogador '[player]' do campeonato com aviso.\n");
    printf(" X > s[player]\n");
    printf("\tSuspende output entre o jogo e o jogador '[player]'.\n");
    printf(" X > r[player]\n");
    printf("\tSuspende output entre o jogo e o jogador '[player]'.\n");
    printf("   > exit\n");
    printf("\tEncerrar o arbitro.\n");
}

void lista_jogadores(Jogadores *lista) {
    if (lista == NULL) {
        printf("Nao ha jogadores ligados...\n");
        return;
    }
    Jogadores *temp = lista;
    Comm_cli *temp_comm;
    int listado = 0;
    printf("\nLista de jogadores (ativos):\n");
    do {
        temp_comm = &temp->cli;
        if (temp_comm->fim == 0) {
            printf("\t > %s [%d]\n", temp_comm->nome, temp_comm->pid);
            listado = 1;
        }
        temp = temp->seg;
        if (temp == NULL) break;
    } while(1);
    lista = temp;
    printf("\tNenhum jogador ativo...\n");
}

int procura_jogador(Jogadores *lista, char *nome) {
    if (lista == NULL) {
        return 0;
    }
    Jogadores *temp = lista;
    Comm_cli *temp_comm;
    do {
        temp_comm = &temp->cli;
        if (strcmp(temp_comm->nome, nome) == 0)
            return 1;
        // printf("%s", temp_comm->nome);
        temp = temp->seg;
    } while(temp != NULL);
    // lista = temp;
    return 0;
}

void *executa_jogo(void *dados) {
    pid_t pid = fork(); //fork process
    TDATA *ponteiro_data = dados;
    
    printf("args: [1] %s [2] %d\n", ponteiro_data->jogo, ponteiro_data->pid);
    char *game[2];
    game[0] = (char *)malloc(sizeof(ponteiro_data->jogo)+3);
    sprintf(game[0], "./%s", ponteiro_data->jogo);
    
    game[1] = NULL;
    printf("@thread: jogo %s\n", game[0]);

    if (pid == -1) { //error
        char * error = strerror(errno);
        printf("error fork!!\n");
    } 
    
    else if (pid == 0) { // child process
        execvp(game[0], game); //exec cmd
        char * error = strerror(errno);
        printf("unknown command\n");
    } 
    
    else { // parent process
        int childstatus;
        printf("PID: %d\n", pid);
        waitpid(pid, & childstatus, 0);
        // return 1;
    }
   
    int* res = (int *)malloc(sizeof(int));
    *res = 123;
    pthread_exit(res);
};

Jogadores *adiciona_jogador(Jogadores *lista, Comm_cli pedido, pthread_mutex_t *trinco) {
    if (lista == NULL) {
        // INFO PARA ESTRUTURA JOGADORES
        Jogadores *novo = (Jogadores *) malloc(sizeof(Jogadores));

        // COPIAR INFO CLIENTE
        novo->cli.pid = pedido.pid;
        strcpy(novo->cli.nome, pedido.nome);
        strcpy(novo->cli.jogo, pedido.jogo);
        novo->cli.pontuacao = pedido.pontuacao;
        strcpy(novo->cli.comando, pedido.comando);
        novo->cli.fim = pedido.fim;

        // INFO PARA ESTRUTURA THREADS
        pthread_t *novaThread = (pthread_t *) malloc(sizeof(pthread_t));
        printf("[AVISO] A criar thread para cliente '%s'", pedido.nome);
        TDATA thread_info;
        strcpy(thread_info.jogo, novo->cli.jogo);
        thread_info.pid = novo->cli.pid;
        pthread_create(&novo->thread, NULL, (void*)executa_jogo, (void *)&thread_info);
        novo->thread = *novaThread;

        // CRIA PIPE PARA 

        // COPIAR INFO GERAL
        novo->seg = NULL;
        printf("\n[AVISO] Jogador %s [%d] adicionado.\n", pedido.nome, pedido.pid);

        return novo;
    } else {
        Jogadores *temp = lista;
        do {
            if (lista->seg == NULL) break;
            lista = lista->seg;
        } while (1);
        debug("Tenho lista a NULL", NULL, -1);

        Jogadores *novo = (Jogadores *) malloc(sizeof(Jogadores));
        // printf("copia info a temp novo");
        novo->cli.pid = pedido.pid;
        strcpy(novo->cli.nome, pedido.nome);
        strcpy(novo->cli.jogo, pedido.jogo);
        novo->cli.pontuacao = pedido.pontuacao;
        strcpy(novo->cli.comando, pedido.comando);
        novo->cli.fim = pedido.fim;
        novo->seg = NULL;
        debug("Criei e tenho novo com conteudo", NULL, -1);

        lista->seg = novo;
        debug("Acho que copiei novo para lista vazia", NULL, -1);

        printf("\n[AVISO] Jogador %s [%d] adicionado.\n", pedido.nome, pedido.pid);
        return temp;
    }
}

Jogadores *desativa_jogador(Jogadores *lista, char *nome) {
    Jogadores *temp = lista;
    Comm_cli *temp_comm;
    do {
        temp_comm = &temp->cli;
        if (strcmp(temp_comm->nome, nome) == 0) {
            temp_comm->fim = 1;
            break;
        }
        temp = temp->seg;
    } while(temp != NULL);

    return lista;
}

Jogadores *remove_jogador(Jogadores *lista, char *nome) {
    if (lista == NULL) {
        printf("\n[AVISO] Nenhum jogador para remover...\n");
        return lista;
    }
    int removido = 0;
    Jogadores *temp = lista, *antes = NULL;
    Comm_cli *temp_comm;
    do {
        temp_comm = &temp->cli;
        if (strcmp(temp_comm->nome, nome) == 0) {
            kill(temp_comm->pid, SIGUSR1);
            if (antes == NULL) {
                // remover thread
                pthread_join(lista->thread, NULL);

                // remover jogador
                lista = temp->seg;
                printf("\n[AVISO] Jogador %s [%d] removido.\n", temp_comm->nome, temp_comm->pid);
                free(temp);
                removido = 1;
                break;
            } else {
                // remover thread
                pthread_join(temp->thread, NULL);

                // remover jogador
                antes->seg = temp->seg;
                printf("\n[AVISO] Jogador %s [%d] removido.\n", temp_comm->nome, temp_comm->pid);
                free(temp);
            }
            removido = 1;
            break;
        }
        antes = temp;
        temp = temp->seg;
    } while(temp != NULL);

    if (removido == 0)
        printf("\n[AVISO] Nenhum jogador '%s' removido...\n", nome);

    return lista;
}

int processa_pedido(Comm_cli *pedido, int size) {
    if (strcmp(pedido->comando, "novoNome") == 0)
        return 1;
    else if (strcmp(pedido->comando, "novoNome") == 0) 
        return 2;
    else if (strcmp(pedido->comando, "sair") == 0) 
        return -1;
    return 0;
}

void termina_jogos(Jogadores *lista) {
    if (lista == NULL) {
        printf("[INFO] Nao ha jogadores ligados...\n[INFO] A encerrar normalmente...\n");
        return;
    }
    Jogadores *temp = lista;
    Comm_cli *temp_comm;
    printf("A desligar users...\n");
    do {
        temp_comm = &temp->cli;
        if (temp_comm->fim == 0) {
            kill(temp_comm->pid, SIGINT);
            printf("\t[* INFO] User %s [%d] foi desligado.\n", temp_comm->nome, temp_comm->pid); 
        } else printf("\t[* INFO] User %s [%d] já estava desligado.\n", temp_comm->nome, temp_comm->pid); 
        temp = temp->seg;
        if (temp == NULL) break;
    } while(1);
    lista = temp;
}