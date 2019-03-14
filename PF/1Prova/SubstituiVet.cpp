#include <iostream>
using namespace std;
void SubstituiVet(int vet[], int tam);
void RemoveEfeito(int vet[],int tam);
int main(){
    int vet[7],tam=7;
    for(int i=0;i<7;i++){
        cin>>vet[i];
    }
    SubstituiVet(vet,tam);
}
void SubstituiVet(int vet[], int tam){
    int i,j,acum=0,cont=0,aux=0;
    int vetAux[tam];
    for(int i=tam;i>=1;i--){
        vet[i]=vet[i]-vet[i-1];
    }
    cout<<endl;
}
void RemoveEfeito(int vet[],int tam){
    for(int i=1;i<tam;i++){
        vet[i]=vet[i]+vet[i-1];
    }
}