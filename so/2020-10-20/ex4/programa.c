#include <stdlib.h>
#include <stdio.h>

#include "imprime.h"

int main (void) {
    int i;

    printf("[DEBUG] Inicio...\n");
    for (i = 0; i < 3; i++) {
        imprime("Ola Mundo.");
    }
    printf("[DEBUG] Fim...\n");

    return 0;
}