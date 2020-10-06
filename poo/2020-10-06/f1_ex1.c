#include <stdio.h>
#include <stdlib.h>

// Tamanho máximo do input de string
#define MAX_STR_INPUT 255

int main (int argc, char** argv) {
    int idade;
    char *nome = malloc(MAX_STR_INPUT);

    // Obter input do nome
    printf("INTRODUCAO DE DADOS\n\tNome: ");
    // Usar fgets por ter limitação de input e ser mais seguro
    fgets(nome, MAX_STR_INPUT, stdin);
    // Remover o último \n devido à finalização de inserção de dados
    if (nome[strlen(nome) - 1] == '\n')
        nome[strlen(nome) - 1] = '\0';
    // Obter input da idade
    printf("\tIdade: ");
    scanf("%d", &idade);

    // Mostrar info
    printf("\n%s tem %d anos de idade.\n", nome, idade);

    // Libertar nome (ponteiro com alocação de memória)
    free(nome);

    return 0;
}