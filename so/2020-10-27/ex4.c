#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (void) {
    char str[40];

    do {
        printf("Comando: ");
        fflush(stdout);
        scanf("%s", str);
        execl(str, str, NULL);
        printf("[ERRO] Nao consegui executar a aplicacao!!\n");
    } while (strcmp(str, "sair") != 0);

    exit(0);
}