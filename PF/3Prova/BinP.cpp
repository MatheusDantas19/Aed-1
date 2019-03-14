#include <iostream>
using namespace std;
void Bin(int n){
    int aux,cont,vet[32],acum=0,i,quoc;
    bool flag=false;
    while(flag==false){
        aux=n%2;
        quoc=n/2;
        vet[acum]=aux;
        
        if(n==1){
            vet[acum]=aux;
            break;
        }
        if(n==0){
            vet[acum]=aux;
            break;
        }
        n=quoc;
        acum++;
        
    }
    for(i=acum;i>=0;i--){
        cout<<vet[i];
    }
     
}
int main(){
    int n;
    cin>>n;
    Bin(n);
    cout<<endl;
}