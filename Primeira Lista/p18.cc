//Questão 18
#include <iostream>
#include <stdio.h>
#include <math.h>
#define tam 10
using namespace std;
double DesvioPadrao(double vetor[tam], int n);
int main(){
	double vet[tam];
	int cont=0;
	double desvioPadrao=0.0;
	cout<<"Digite os Valores do vetor: "<<"["<<tam<<"]"<<endl;
	for(cont=0;cont<tam;cont++){
		cin>>vet[cont];
	}	
	desvioPadrao = DesvioPadrao(vet,tam);
	std::cout.precision(2);
	std::cout <<"O Desvio Padrao dos Valores são: "<<std::fixed << desvioPadrao<<endl;
}

double DesvioPadrao(double vetor[tam],int n){
	int cont=0;
	double media=0.0,soma=0.0,var=0.0,desvio=0.0;
	for(cont=0;cont<n;cont++){
		soma=(soma+vetor[cont]);
	}
	media=soma/n;
	for(cont=0;cont<n;cont++){
		var=var+((vetor[cont]-media)*(vetor[cont]-media));
	}
	var=var/n;
	desvio = sqrt(var);
	return desvio;
}
