//Questão 13
/*#include <iostream>
#include <stdio.h>
#define tam 10
using namespace std;
void DiferencaVet(int vet[], int n);
void InverterEfeito(int vet[tam],int n);
int main(){
	int vet[tam];
	int i=0,j=0,aux=0; 
	cout<<"Digite os valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(i=0;i<tam;i++){
		fflush(stdin);
		cin>>vet[i];
	}

	cout<<"\nAs Diferenças do vetor: \n";
	DiferencaVet(vet,tam);
}

void DiferencaVet(int vet[tam], int n){
	int i=0, temp=0, aux=0;
	for(i=n-1;i>=0;i--){
		if(i==0){
			continue;
		}else{
			aux=vet[i]-vet[i-1];
			vet[i]=aux;
		}
		aux=0;
	}
	for(i=0;i<n;i++){
		cout<<vet[i]<<" ";
	}
	InverterEfeito(vet,tam);
}*/

//Função inverter efeito da questão 12
void InverterEfeito(int vet[tam],int n){
	cout<<"\n";
	cout<<"Efeito Invertido: ";
	int i=0, aux=0;
	for(i=1;i<n;i++){
		vet[i]=vet[i]+vet[i-1];
	}
	cout<<"\n";
	for(i=0;i<n;i++){
		cout<<vet[i]<<" ";
	}
}



