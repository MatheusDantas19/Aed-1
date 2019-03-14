//Questão 6
#include <iostream>
#define  tam 10
using namespace std;
void InsertionSort(int vet[tam], int n);
int main(){
	int vet[tam];
	int cont=0;
	cout<<"Digite os Valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(cont=0;cont<tam;cont++){
		cin>>vet[cont];
	}
	cout<<"Vetor Ordenado: \n";
	AlterarValorVet(vet,tam);
}

void InsertionSort(int vet[tam], int n){
	int cont=0,i=0,j=0,res=0,aux=0;
	while(i<n){
		aux=vet[i];
		j=i-1;
		while(j>=0 && aux<vet[j]){
			vet[j+1]=vet[j];
			j=j-1;
		}
		vet[j+1]=aux;
		i++;
	}
	i=0;
	while(i<n){
		cout<<vet[i]<<" ";
		i++;
	}
}