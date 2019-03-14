#include <iostream>
using namespace std;

void Ord(int vet[],int tam){
    int contI=0,contP=0;
    int j,i,aux;
    for(i=1;i<tam;i++){
        aux=vet[i];
        for(j=i-1;j>=0 && aux<vet[j];j--){
            vet[j+1]=vet[j];
        }
        vet[j+1]=aux;
    }
    for(int i=0;i<tam;i++){
        if(vet[i]%2==0) contP++;
        if(vet[i]%2!=0) contI++;
    }
    int vetA[contP],vetB[contI];
    int cont=0,cont1=0;
    for(int i=0;i<tam;i++){
        if(vet[i]%2==0){
            vetA[cont]=vet[i];
            cont++;
        }
        if(vet[i]%2!=0){
            vetB[cont1]=vet[i];
            cont1++;
        }
    }
    cont=0;
    for(i=0;i<contP;i++){
        vet[i]=vetA[i];
        cont++;
    }
    int p=0;
    for(i;i<tam;i++){
        vet[i]=vetB[p];
        p++;
    }
    for(i=0;i<tam;i++){
        cout<<vet[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int vet[6],tam=6;
    for(int i=0;i<tam;i++){
        cin>>vet[i];
    }
    Ord(vet,tam);
}