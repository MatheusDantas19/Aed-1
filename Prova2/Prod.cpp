#include <iostream>
#include <stdlib.h>
using namespace std;
int Prod(int vet[], int fim);
int main(){
	int vetA[5];
	for(int i=0;i<6;i++){
		cin>>vetA[i];
	}
	cout<<Prod(vetA,6)<<endl;

}
int Prod(int vet[], int fim){
	if(fim==1)
		return vet[0];
	return vet[fim-1]*Prod(vet,fim-1);
	
}