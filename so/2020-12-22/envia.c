#include "util.h"

int continua = 1;

void termina(int s) { /* funcao de tratamento do sinal */
    continua = 0;
}

int main(void) {

    PEDIDO p;

    /* VERIFICA SE TEM UM ARGUMENTO DA LINHA DE COMANDOS */
    /* ABRE FIFO (ARGV[1]) PARA ESCRITA - open() */
    /* PEDE NOME AO UTILIZADOR */
    /* OBTEM PID DO PROCESSO - getpid() */
    /* TRATA O SINAL (SIGUSR1)- sigaction() */
    do {
        /* PEDE NUMERO AO UTILIZADOR */
        /* ENVIAR PEDIDO AO SERVIDOR - write() */
    } while(continua);
    /* FECHA FIFO - close() */

    exit(0);
}