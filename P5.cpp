//Questão 5
#include <iostream>
#define  tam 10
using namespace std;
int VetorCrescente(int vetor[tam], int n);
int main(){
	int vet[tam];
	int i=0;
	cout<<"Digite os Valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(i=0;i<tam;i++){
		cin>>vet[i];
	}
	cout<<"Retorno: "<<VetorCrescente(vet,tam)<<endl;
}

int VetorCrescente(int vetor[tam], int n){
	int i=0,j=0,cont=0,resultado=0;
	for(i=0;i<n;i++){
		cont=0;
		for(j=1;j<n;j++){
			if(vetor[i]<vetor[j]){
				cont++;
			}
		}
		if(cont==n-1){
			resultado=1;
		}
	}
	return resultado;
}