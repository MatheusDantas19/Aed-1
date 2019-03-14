#include <iostream>
using namespace std;
int m;
int ParC(int n){
    if(n==m+1) return 0;
    if(n%2==0) cout<<n<<" ";
    ParC(n+1);
    
        
}
int ParD(int n){
    if(n==0) return 0;
    else{
        if(n%2==0) cout<<n<<" ";
        ParD(n-1);
    }

}
int cont=0;
int Dig(int n,int k){
    
    if(n==0) {
        cout<<cont<<endl;
        return 0;
    }
    if(n%10==k){
        cont++;
        Dig(n/10,k);
    }else Dig(n/10,k); 
}

int main(){
    int n,k;
    cin>>n>>k;
    Dig(n,k);
    
}