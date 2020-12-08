#ifndef ARBITRO_H
#define ARBITRO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h> // biblio para listar ficheiros
#include <time.h>
#include <signal.h>

#include "constantes.h"
#include "../estruturas.h"

void print_commcli(Comm_cli *temp, int size);
void debug(char *texto, Comm_cli *temp, int size);
void check_envVariables(char *gamedir, char *maxPlayers, int int_MAXPLAYERS);
void check_argumentos(int t_campeonato, int t_espera);
int total_jogos(Jogos *lista);
void lista_jogos(Jogos *lista);
char *nome_jogo(Jogos *lista, int num);
Jogos *obtem_jogos(char env_GAMEDIR[]);
void lista_jogadores(Jogadores *lista);
int procura_jogador(Jogadores *lista, char *nome);
Jogadores *adiciona_jogador(Jogadores *lista, Comm_cli pedido);
Jogadores *desativa_jogador(Jogadores *lista, char *nome);
Jogadores *remove_jogador(Jogadores *lista, char *nome);
int processa_pedido(Comm_cli *temp, int size);
void termina_jogos(Jogadores *lista);

#endif // ARBITRO_H