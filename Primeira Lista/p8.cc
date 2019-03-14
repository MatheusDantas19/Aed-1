//Quetsão 8
#include <iostream>
using namespace std;
int QuantidadeChar(char nome[],char letra[]);
int main(){
    char nome[50];
    char letra[50];
    cout<<"Digite o nome: "<<endl;
    cin>>nome;
    cout<<"Digite uma letra: "<<endl;
    cin>>letra;
    cout<<"Retorno: "<<QuantidadeChar(nome,letra)<<endl;
}
int QuantidadeChar(char nome[], char letra[]){
    int i=0,cont=0;
    for(i=0;i<50;i++){
        if(nome[i]=='\0'){
            break;
        }
        if(nome[i]==letra[0]){
            cont++;
        }
        else if(nome[i]==letra[0]-32){
            cont++;
        }else if(nome[i]==letra[0]+32){
            cont++;
        }
    }
    return cont;
}