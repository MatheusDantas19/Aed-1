//Questão 11
#include <iostream>
#include <stdio.h>
#define tam 10
using namespace std;
void Delta(int vetor[tam], int n, int num);
int main(){
	int vet[tam],cont=0, numero=0;
	cout<<"Digite um numero Delta\n";
	cin>>numero;
	cout<<"Digite os valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(cont=0;cont<tam;cont++){
		cin>>vet[cont];
	}	
	cout<<"Vetor com a Diferença:"<<endl;
	Delta(vet,tam,numero);

}

void Delta(int vetor[tam],int n, int num){
	int cont=0,delta=0;
	for(cont=0;cont<n;cont++){
		delta = vetor[cont]-num;
		vetor[cont] = delta;
	}

	for(cont=0;cont<n;cont++){
		cout<<vetor[cont]<<" ";
	}
}
