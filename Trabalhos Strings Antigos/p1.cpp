#include <iostream>
using namespace std;
#define tam 7
void removPrimo(int vet[]);
int main(){
    int vet[tam],i;
    for(i=0;i<tam;i++){
        cin>>vet[i];
    }
    removPrimo(vet);
}

void removPrimo(int vet[]){
    int veta[tam],i=0,j=0,cont=0,aux=0,acum=0;
    for(i=0;i<tam;i++){
        cont=0;
        for(j=1;j<=vet[i];j++){
            if((vet[i]%j)==0){
                cont++;
            }
        }
        if(cont==2){
            veta[acum]=vet[i];
            acum++;
        }else{
            aux++;
            vet[i]=0;
            veta[tam-aux]=vet[i];
        }
    }
    for(i=0;i<tam;i++){
        cout<<veta[i]<<" ";
    }
}