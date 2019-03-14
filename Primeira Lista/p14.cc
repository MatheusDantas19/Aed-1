//Questão 14
#include <iostream>
#define tam 10
using namespace std;
int Busca(int chave, int vet[]);
int main(){
    int vet[tam];
    int i=0, chave=0;
    cout<<"Digite os valores do vetor: "<<"["<<tam<<"]"<<endl;
    for(i=0;i<tam;i++){
        cin>>vet[i];
    }
    cout<<"Digite o valor da chave: "<<endl;
    cin>>chave;
    cout<<"Retorno: "<<Busca(chave,vet)<<endl;
}

int Busca(int chave, int vet[]){
    int inicio=0, fim=tam-1, meio=0;
    while(inicio<=fim){
        meio=((inicio+fim)/2);
        if(vet[meio]==chave){
            return meio;
        }else if(chave<vet[meio]){
                fim=meio-1;
        }else{
            inicio=meio+1;
        }  
    }
    return -1;
}
    