//Questão 2
#include <iostream>
#define  tam 10
using namespace std;
void AlterarValorVet(int vet[tam], int n);
int main(){
	int vet[tam];
	int cont=0;
	cout<<"Digite os Valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(cont=0;cont<tam;cont++){
		cin>>vet[cont];
	}
	cout<<"Vetor Modificado:\n";
	AlterarValorVet(vet,tam);
}

void AlterarValorVet(int vet[tam], int n){
	int cont, res=0;
	for(cont=0;cont<n;cont++){
		if(vet[cont]<=0){
			res=vet[cont]=-2;
		}else if(vet[cont]>=1 && vet[cont]<=5){
			res=vet[cont]=1;
		}else{
			res=vet[cont]=0;
		}
	cout<<res<<endl;
	}
}