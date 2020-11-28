#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    int i;

    printf("Tenho o PID = %d.\n", getpid());
    printf("Inicio...\n");
    for (i=0; i<6; i++) {
        printf("+");
        fflush(stdout);
        sleep(3);
    }
    printf("\nFim!\n");
    exit(3);
}