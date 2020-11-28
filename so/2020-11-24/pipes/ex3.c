#include "util.h"

int main(void) {
    int fd, fdr, n;
    PEDIDO p;

    // criar fifo do servidor
    if (access(FIFO_SRV, F_OK) != 0) { // =0 -> fich existe
        mkfifo(FIFO_SRV, 06000);
    }
    printf("Criei o fifo...\n");
    fd = open(FIFO_SRV, O_RDONLY);
    do {
        // read pedido do fifo....
        n = read(fd, &p, sizeof(PEDIDO));
        printf("Recebi.. %d %c %d (%d bytes)\n", p.num1, p.op, p.num2, n);

        if (n == sizeof(PEDIDO)) {
            // calcula resultado (adaptar para tipo de operação)
            p.res = p.num1 + p.num2;

            // envia resposta para cliente
            fdr = open(FIFO_CLI, O_WRONLY);
            n = write(fdr, &p, sizeof(PEDIDO));
            close(fdr);
            printf("Escrevi.. %d %c %d = %.2f (%d bytes)\n", p.num1, p.op, p.num2, p.res, n);
        }
    } while (p.op != 's');
    close(fd);
    // apagar fifo do servidor
    unlink(FIFO_SRV);

    exit(0);
}