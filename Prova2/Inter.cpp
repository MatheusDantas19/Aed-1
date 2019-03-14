#include <iostream>
#include <stdlib.h>
using namespace std;
void intercalar(int vetA[],int vetB[],int tamA,int tamB);
void imprimeVet(int Vet[],int tamF);
void Quick(int vetor[], int inicio, int fim);
int main(){
	int vetA[5],vetB[5];
	for(int i=0;i<5;i++){
		cin>>vetA[i];
	}
	for(int i=0;i<5;i++){
		cin>>vetB[i];
	}
	intercalar(vetA,vetB,5,5);
	//cout<<vetC[0];

}
void intercalar(int vetA[],int vetB[],int tamA,int tamB){
	int *vetC;
	int tamF=tamA+tamB;
	vetC=(int*)malloc(sizeof(int)*tamF);
	int p=0;
	for(int i=0;i<tamA;i++){
		vetC[p]=vetA[i];
		p=p+2;
	}
	p=1;
	for(int i=0;i<tamB;i++){
		vetC[p]=vetB[i];
		p=p+2;
	}
	for(int i=0;i<tamF;i++){
		cout<<vetC[i]<<" ";
	}
	Quick(vetC,0,tamF);
	imprimeVet(vetC,tamF);	
}
void Quick(int vetor[], int inicio, int fim){   
   int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;
   meio = ((i + j) / 2);
   pivo = vetor[meio];
   do{
      while (vetor[i] < pivo) i++;
      while (vetor[j] > pivo) j--;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i++;
         j--;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   
}
void imprimeVet(int Vet[],int tamF){
	cout<<"\nOrdenado: "<<endl;
	for(int i=0;i<tamF;i++){
		cout<<Vet[i]<<" ";
	}
}