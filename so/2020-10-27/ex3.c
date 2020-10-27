#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[], char *envp[]) {
    int i, n, t=1;
    char *str;

    if (argc!=3) {
        printf("[ERRO] Nr. de args!\n");
        exit(3);
    }
    n=atoi(argv[1]);
    str = getenv("TEMPO");
    if (str != NULL) 
        t = atoi(str);
    
    printf("INICIO...\n");
    for (i=0; i<n; i++) {
        printf("%s", argv[2]);
        fflush(stdout);
        sleep(t);
    }

    printf("\nFIM!!!\n");

    return 0;
}