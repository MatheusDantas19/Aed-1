//Questão 10
#include <iostream>
#define tam 2
using namespace std;
int Busca(int chave, int vet[]);
int main(){
    bool encontrado =false;
    int vet[tam];
    int i=0,meio=0,inicio=0,fim=0,chave=0,f;
    cout<<"Digite os valores do vetor: "<<"["<<tam<<"]"<<endl;
    for(i=0;i<tam;i++){
        cin>>vet[i];
    }
    inicio=0;
    fim=tam-1;
    cout<<"Digite o valor da chave: "<<endl;
    cin>>chave;
    cout<<"Retorno: "<<Busca(chave,vet)<<endl;
}

int Busca(int chave, int vet[]){
    int inicio=0, fim=tam-1, meio=0,res=0;;
    while(inicio<=fim && chave !=vet[meio]){
        meio=(inicio+fim)/2;
        if(chave==vet[meio]){
            res=1;
        }else{
            res=0;
        }
        if(chave<vet[meio]){
            fim=meio-1;
        }else{
            inicio=meio+1;
        }
        return res;
    }
}
    