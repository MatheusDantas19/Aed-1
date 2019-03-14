//Questão 3
#include <iostream>
#define  tam 10
using namespace std;
void InvertendoVet(int vetor[tam], int n);
int main(){
	int vet[tam];
	int cont=0, i=0;
	cout<<"Digite os Valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(i=0;i<tam;i++){
		cin>>vet[i];
	}
	cout<<"Vetor Invertido:\n ";
	InvertendoVet(vet,tam);
}

void InvertendoVet(int vetor[tam], int n){
	int i,aux=0;
	for(i=0;i<n/2;i++){
		aux=vetor[i];
		vetor[i]=vetor[n-i-1];
		vetor[n-i-1]=aux;
	}
	for(i=0;i<n;i++){
		cout<<vetor[i]<<" ";
	}	
}