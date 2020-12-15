#include "util.h"

typedef struct {
    char letra;
    int continua; // flag (pode ser char)
    pthread_mutex_t *ptrinco;
} TDATA;

void *mostra(void *dados) {
    TDATA *ponteiro_data = (TDATA *)dados;
    int *res;
    /* thread #1 */
    do {
        for (int i=0; i<rand()%5; i++) {
            printf("."); fflush(stdout); sleep(1);
        }
// TRANCAR();
pthread_mutex_lock(ponteiro_data->ptrinco);
        for (int i=0; i<3; i++) {
            printf("%c", ponteiro_data->letra); 
            fflush(stdout); 
            sleep(1);
        } /** nao queremos que este for seja interrompido **/
// DESTRANCAR();
pthread_mutex_unlock(ponteiro_data->ptrinco);
    } while(ponteiro_data->continua);

    res = (int *)malloc(sizeof(int));
    *res = 123;
    /* termina thread #1 */
    pthread_exit(res);
}

int main(void) {
    char str[40];
    int *resultado;
    TDATA thread_info[NTHREADS];
    pthread_t tarefa[NTHREADS];
pthread_mutex_t trinco;

pthread_mutex_init(&trinco, NULL);
    printf("Sou o processo %d...\n", getpid());
    srand((unsigned int) time(NULL));
    for (int i=0; i<NTHREADS; i++) {
        thread_info[i].letra = 'A'+i;
        thread_info[i].continua = 1;
        thread_info[i].ptrinco = &trinco;
        pthread_create(&tarefa[i], NULL, mostra, (void *)&thread_info[i]);
    }

    do {
        /* thread #0 */
        printf("COMANDO: ");
        scanf("%s", str);
        printf("Recebi o comando '%s'...\n", str);
    } while(strcmp(str, "sair") != 0);

    printf("Vou pedir a thread #1 para terminar.... "); fflush(stdout);
    for (int i=0; i<NTHREADS; i++) {
        thread_info[i].continua = 0;
        /* esperar pelo find a thread que criei */
        pthread_join(tarefa[i], (void *) &resultado);
        printf("Terminou (%d)... ", *resultado);
    }
    free(resultado);
    printf("\n");

pthread_mutex_destroy(&trinco);
    /* termina thread #0 */
    exit(0);
}