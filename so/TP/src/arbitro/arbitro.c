#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constantes.h"
#include "../estruturas.h"

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

    Jogador oi;

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

    return FIM_BOM;
}