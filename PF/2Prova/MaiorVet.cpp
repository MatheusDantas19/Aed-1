#include <iostream>
using namespace std;
int maior(int vet[], int tam){
    if(tam==1) return vet[0];
    else{
        int maior2=maior(vet,tam-1);
        if(maior2>vet[tam-1]) return maior2;
        else return vet[tam-1];
    }
}
int main(){
    int vet[5];
    for(int i=0;i<5;i++) cin>>vet[i];
    cout<<maior(vet,5)<<endl;
}