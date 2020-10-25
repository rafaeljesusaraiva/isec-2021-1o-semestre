#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    int i;

    for (i=0; i<argc; i++)
        printf("ARG[%d] = '%s'\n", i, argv[i]);

    i = atoi(argv[2]);
    printf("Vou permitir %d jogadores!\n", i++);

    return 0;
}