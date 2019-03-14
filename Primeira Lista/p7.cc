//Questão 7
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int SomaQuadrado(int n);
int main(){
	int numero;
	fflush(stdin);
	cout<<"Digite um numero: "<<endl;
	cin>>numero;
	cout<<"A Soma dos Quadrados: "<<SomaQuadrado(numero)<<endl;
}
int SomaQuadrado(int n){
	int cont=0, soma=0;
	for(cont=1;cont<=n;cont++){
		soma+=cont*cont;
	}
	return soma;
}
