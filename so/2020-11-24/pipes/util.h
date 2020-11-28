#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_SRV "tubo"
#define FIFO_CLI "cli"

typedef struct {
    int num1, num2;
    char op; /* + - * / s */
    float res;
} PEDIDO;