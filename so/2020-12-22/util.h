#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

/* ESTRUTURA DE DADOS PARA COMUNICAR ENTRE CLIENTE E SERVIDOR */
typedef struct {
    char nome[20];
    int num;
    int pid;
} PEDIDO;

#endif