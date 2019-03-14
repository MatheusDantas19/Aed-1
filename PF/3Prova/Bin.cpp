#include <iostream>
using namespace std;
void Bin(int n){
    if(n/2!=0){
        Bin(n/2);
    }
    cout<<n%2;
   // if(n==0) return 0;
     
}
int main(){
    int n;
    cin>>n;
    Bin(n);
    cout<<endl;
}