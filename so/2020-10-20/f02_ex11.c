#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[], char *envp[]) {
    int i;

    char *str;

    for (i=0; i<argc; i++)
        printf("ARG[%d] = '%s'\n", i, argv[i]);

    i = atoi(argv[2]);
    printf("Vou permitir %d jogadores!\n", i++);

    for (i=0; envp[i] != NULL; i++)
        printf("VAR[%d] = '%s'\n", i, envp[i]);

    str = getenv("HOME");
    printf("O user tem a diretoria principal em:\n\t%s\n", str);

    return 0;
}