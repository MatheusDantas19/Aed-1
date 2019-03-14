#include <iostream>
using namespace std;
void RemovePrimo(int vet[], int tam);
int main(){
    int vet[7],tam=7;
    for(int i=0;i<7;i++){
        cin>>vet[i];
    }
    RemovePrimo(vet,tam);
}
void RemovePrimo(int vet[], int tam){
    int i,j,acum=0,cont=0,aux=0;
    int vetAux[tam];
    for(int i=0;i<tam;i++){
        for(j=1;j<=vet[i];j++){
            if(vet[i]%j==0){
                cont++;
            }
        }
        if(cont==2){
            vetAux[acum]=vet[i];
            acum++;
        }else{
            aux++;
            vetAux[tam-aux]=0;
        }
        cont=0;
    }
    for(int i=0;i<tam;i++){
        vet[i]=vetAux[i];
        cout<<vet[i]<<" ";
    }
    cout<<endl;
}