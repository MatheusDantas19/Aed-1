#include <iostream>
#include <stdlib.h>
using namespace std;
int Maior(int vet[], int fim);
int main(){
	int vetA[6];
	for(int i=0;i<6;i++){
		cin>>vetA[i];
	}
	cout<<Maior(vetA,6)<<endl;

}
int Maior(int vet[], int tam){
	int maior;
	if(tam==1){
		return vet[0];
	}else{
		maior=Maior(vet,tam-1);
		if(vet[tam-1]>maior){
			return vet[tam-1];
		}else return maior;
	}
}