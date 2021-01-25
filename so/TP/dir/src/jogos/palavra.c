#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int pontos=0;

void sair (int s){
	printf("Ficou com %d pontos!!!",pontos);
	exit(pontos);
}

int main(){

	char adivinha;
	char frase[20] ={'e','x','t','r','a','o','r','d','i','n','a','r','i','a','m','e','n','t','e','\0'};
	char fraseadv[20] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0'};
	int totaltenta=20;
	int i,j;
	int pontos=0;

	signal(SIGUSR1, sair);

	printf("               _____      _                       ");
    printf("     /\\       |  __ \\    | |                      ");
    printf("    /  \\      | |__) |_ _| | __ ___   ___ __ __ _ ");
    printf("   / /\\ \\     |  ___/ _` | |/ _` \\ \\ / / '__/ _` |");
    printf("  / ____ \\    | |  | (_| | | (_| |\\ V /| | | (_| |");
    printf(" /_/    \\_\\   |_|   \\__,_|_|\\__,_| \\_/ |_|  \\__,_|");
    printf("                                                  ");

    printf("\n\n\tBem vindo ao jogo, A PALAVRA");
    printf("\n\n\tEste jogo consiste em adivinhar a maior quantidade de letras possiveis, para consequentemente, ganhar mais pontos (+1) e completar a palavra. Caso seja inserida uma letra errada, perde-se pontos (-1).");

	printf("\n\tAdivinha a frase!");

	for(i=0;i< totaltenta; i++){
		printf("Qual e o caracter? ");
		scanf("%c\n",&adivinha);

		int flag = 0;
		
		for(j=0;j<20;j++)
			if(adivinha==frase[i]){
				fraseadv[i]=adivinha;
				flag++;
			}
			
		if (flag > 0) {
			pontos += flag;
		} else {
			pontos--;
		}
			
	}
}