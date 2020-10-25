#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define ERRO 5 /* codigo erro */

int main (void) {
#ifdef DEBUG
    printf("[DEBUG] Inicio...\n");
#endif

printf("Ola Mundo.\n");

#ifdef DEBUG
    printf("[DEBUG] Fim...\n");
#endif
}