/////////////////////// Protótipos de funções ////////////////////////////

#include <stdio.h>
#include <string.h>

typedef struct Contato {
        int idade;
        char nome[20];
    } Contato;

int trocaIdade(int*, int*);
char trocaNome(char*, char*);

//////////////////////////////////////////////////////////////////////////
int main(){
	Contato contato[100];
	int NUM = 0;

	printf("N: ");
	scanf("%i", &NUM);

	for (int i = 0; i < NUM; i++) {
        printf("Nome: ");
		scanf("%s", &contato[i].nome);
        printf("Idade: ");
		scanf("%i", &contato[i].idade);
	}

	for (int j = NUM; j >= 0; j--){
		for(int i = 0; i < j; i++){
			if(contato[i].idade > contato[i + 1].idade){
				trocaIdade(&contato[i].idade, &contato[i + 1].idade);
				trocaNome(contato[i].nome, contato[i + 1].nome);
			}
		}
	}

	printf("Saida: \n");
	for (int i = 0; i < NUM; i++) {
		printf("Nome: %s Idade: %d\n", contato[i].nome, contato[i].idade);
	}
	printf("\n");

}

/////////////////////// Definição de funções /////////////////////////////

int trocaIdade(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
}

char trocaNome(char *a, char *b){
	char s[20];
	strcpy(s, a);
	strcpy(a, b);
	strcpy(b, s);
}