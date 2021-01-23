#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include "utils.h"
#include <unistd.h>


typedef struct {
    int pid;
    char nome[30];
    char jogo[1024];
    int pontuacao;
    char comando[30];
    int fim; 
    // -1 => falta nome
    // 0  => jogo decorre
    // 1  => jogo acaba
} Comm_cli;

typedef struct thread_data {
    char *jogo;
    int pid;
} TDATA;

typedef struct jogad {
    Comm_cli cli;
    pthread_t thread;
    TDATA thread_info;
    struct jogad *seg;
} Jogadores;

typedef struct jogos {
    char nome[1024];
    struct jogos *seg;
} Jogos;

// struct estruturas {
//     /* data */
// };

#endif // ESTRUTURAS_H