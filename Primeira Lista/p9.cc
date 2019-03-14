//Questão 9
#include <stdio.h>
#include <iostream>
#include <string.h>
#define tam 40
using namespace std;
void inverte(char nome[],char invertido[]);
int palindromo(char nome[],char invertido[]);
int main(){
	int i = 0, cont = 0, j = 0;
	char nome[tam], invertido[tam];
	printf("Digite o nome:\n");
   	cin>>nome;
	inverte(nome,invertido);
	cout<<"Retorno: "<<palindromo(nome,invertido)<<endl;
}

void inverte(char nome[],char invertido[]){
	//Ordem inversa
	int i=0,j=0,cont=0;
	while (nome[i] != '\0'){
		cont++;
		i++;
	}
	for(i = cont; i >= 0; i--){
		if (nome[i] != '\0'){
			invertido[j] = nome[i];
			j++;
		}  
	}
	invertido [j] = '\0';	
}

int palindromo(char nome[],char invertido[]){
	int resposta=0;
	if(strcmp(nome, invertido) == 0){
		resposta = 1;
	}else{
		resposta = 0;
	}
	return resposta;
}


