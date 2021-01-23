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

	printf("Adivinha a frase! Tens 20 tentativas!\n");

	for(i=0;i< totaltenta; i++){
		printf("Qual e o caracter? ");
		scanf("%c\n",&adivinha);
		
		for(j=0;j<20;j++)
			if(adivinha==frase[i]){
				fraseadv[i]=adivinha;
				pontos++;
			}
	}
}