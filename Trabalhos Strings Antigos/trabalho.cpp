#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int i,j,cont=0;
    char aux[255];
    char temp[255];
    char aux1[255];
    cin.getline(aux,255);
    int n=strlen(aux);
    for(i=0,j=0;i<n;i++){
        if((aux[i] >= 0 && aux[i] <= 31) 
            || (aux[i] >= 35 && aux[i] <= 38)
            || (aux[i]==47) 
            || (aux[i] >= 42 && aux[i] <= 43) 
            || (aux[i] == 45)
            || (aux[i] == 33)
            || (aux[i] >= 60 && aux[i] <= 64)
            || (aux[i] >= 91 && aux[i] <= 96)
            || (aux[i] >= 123 && aux[i] <= 127))
            {
                continue;
            }else{
                temp[j]=aux[i];
            }
            j++;
    }
    int m = strlen(temp);
    for(j=0,i=0;j<m;j++){
        
        if(temp[j]==32){
            if(temp[j+1]==32){
                cont++;
            }
            else{
                aux1[i]=temp[j];
                
            }
        }else{
            aux1[i]=temp[j];
        }
        if(isspace(temp[j])&&isspace(temp[j+1])){
            cont++;
            if(cont>=1){
                continue;
            }else{
                aux1[i]=temp[j]; 
            }
        }
        i++;
    }
    aux1[i]='\0';
    temp[j]='\0';
    cout<<temp<<endl;
    cout<<"\n";
    cout<<aux1<<endl;
    cout<<cont;
}