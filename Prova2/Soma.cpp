#include <iostream>
#include <stdlib.h>
using namespace std;
int Soma(int vet[], int fim);
int main(){
	int vetA[5];
	for(int i=0;i<6;i++){
		cin>>vetA[i];
	}
	cout<<Soma(vetA,6)<<endl;

}
int Soma(int vet[], int fim){
	if(fim==1){
		return vet[0];
	}else{
		return vet[fim-1]+Soma(vet,fim-1);
	}
}