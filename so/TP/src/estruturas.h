#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include "utils.h"
#include <unistd.h>

typedef struct {
    int pid;
    char nome[30];
    char jogo[10];
    int pontuacao;
    char comando[30];
    int fim; 
    // -1 => falta nome
    // 0  => jogo decorre
    // 1  => jogo acaba
} Comm_cli;

// struct estruturas {
//     /* data */
// };

#endif // ESTRUTURAS_H