#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constantes.h"
#include "../estruturas.h"

int main(int argc, char *argv[]) {

    // ./arbitro -t [tempo campeonato] -e [tempo espera]

    // OBTER VARIAVEIS
    char *env_GAMEDIR = getenv("GAMEDIR");
    char *env_MAXPLAYERS = getenv("MAXPLAYERS");
    

    //Verificaçao das variaveis de ambiente
    if (env_GAMEDIR == NULL || env_MAXPLAYERS == NULL)
        return ERRO_FALTA_ENV;

    // Verificar se env_MAXPLAYERS <= 30 e env_MAXPLAYERS >= 2
    // Limite máx -> MAXDEFINEDPLAYERS
    int int_MAXPLAYERS = atoi(env_MAXPLAYERS);
    if (int_MAXPLAYERS >= MAXDEFINEDPLAYERS || int_MAXPLAYERS <= MINPLAYERS)
		return ERRO_MAXPLAYERS_EXCEDIDO;

	// OBTER ARGUMENTOS
    int opt;
    while((opt = getopt(argc, argv, "t:e:")) != -1) {  
        switch(opt) {   
            case 't':
                printf("tempo campeonato (opcao %c): %s\n", opt, optarg);  
                break;  
            case 'e':
                printf("tempo espera: %s\n", optarg);  
                break;
            case '?':  
                printf("opcao desconhecida (%c): %c\n", opt, optopt); 
                break;  
        }  
    }

    return FIM_BOM;
}