#include "util.h"

typedef struct {
    char fifo[20];
    int continua; // flag (pode ser char)
    pthread_mutex_t *ptrinco;
} TDATA;

void acorda(int s) {}

void *mostra(void *dados) {
    TDATA *ponteiro_data = (TDATA *)dados;
    int *res = (int *)malloc(sizeof(int)); // num pedidos que chegaram ao cliente
    *res = 0;
    /* TRATAR O SINAL (SIGUSR1) - sigaction() */
    /* CRIAR FIFO - mkfifo(...); */
    /* ABRIR FIFO (O_RDWR) - open(...) */
    do {
        /* RECEBER INFORMACAO DO CLIENTE - read(...) */
        pthread_mutex_lock(ponteiro_data->ptrinco);
        /* ENVIAR INFORMACAO PARA O MONITOR - printf(...) */
        *res += 1;
        pthread_mutex_unlock(ponteiro_data->ptrinco);
    } while(ponteiro_data->continua);
    /* OPCIONAL - AVISAR O CLIENTE PARA SAIR COM SINAL (SIGUSR1) ... - kill() */
    /* FECHAR FIFO - close(...) */
    /* ELIMINAR FIFO - unlink(...) */
    pthread_exit(res);
}

int main(void) {
    char str[40];
    int *resultado;
    TDATA thread_info[2];
    pthread_t tarefa[2];
pthread_mutex_t trinco;

pthread_mutex_init(&trinco, NULL);
    printf("Sou o processo %d...\n", getpid());
    srand((unsigned int) time(NULL));
    
    strcpy(thread_info[0].fifo, "ESQ");
    thread_info[0].continua = 1;
    thread_info[0].ptrinco = &trinco;
    pthread_create(&tarefa[0], NULL, mostra, (void *)&thread_info[0]);

    strcpy(thread_info[1].fifo, "DIR");
    thread_info[1].continua = 1;
    thread_info[1].ptrinco = &trinco;
    pthread_create(&tarefa[1], NULL, mostra, (void *)&thread_info[1]);

    do {
        printf("COMANDO: ");
        scanf("%s", str);
        printf("Recebi o comando '%s'...\n", str);
    } while(strcmp(str, "sair") != 0);

    printf("Vou pedir a thread #1 para terminar.... "); fflush(stdout);
    for (int i=0; i<2; i++) {
        thread_info[i].continua = 0;
        /* ENVIAR SINAL (SIGUSR1) A THREAD P/ DESBLOQUEAR O 'READ' - pthread_kill() */
        pthread_join(tarefa[i], (void *) &resultado);
        printf("Thread #%d terminou (%d)... ", i, *resultado);
    }
    free(resultado);
    printf("\n");

    pthread_mutex_destroy(&trinco);
    /* termina thread #0 */
    exit(0);
}