#include <iostream>
#include <string.h>
void removeEspeciais(char aux[], char temp[]){
    int n=strlen(aux);
    int i,j;
    for(i=0,j=0;i<n;i++){
        if((aux[i] ==32 || aux[i]==34 ) 
        || (aux[i] ==32 || aux[i]==34 ) 
        || (aux[i] >=39 && aux[i]<=41 )
        ||(aux[i] ==44 || aux[i]==46 ) 
        || (aux[i] >=48 && aux[i]<=59 ) 
        || (aux[i] >=65 && aux[i]<=90 )
        || (aux[i] >=97 && aux[i]<=122 ))
            
            {
                temp[j]=aux[i];
            }else{
                continue;
            }
            j++;
    }
}
void removEspacos(char temp[], char aux1[]){
    int m = strlen(temp);
    int cont=0,i,j;
    for(j=0,i=0;j<m;j++){
        cont=0;
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
}

using namespace std;
void imprimeChar(char temp[], char aux1[]){
    cout<<"\n";
    cout<<"Versão limpa 1.0: "<<endl;
    cout<<temp<<endl;
    cout<<"\n";
    cout<<"Versão limpa 2.0: "<<endl;
    cout<<aux1<<endl;
}

int main(){
    char aux[500];
    char temp[500];
    char aux1[500];
    cin.getline(aux,500);

    removeEspeciais(aux,temp);
    removEspacos(temp,aux1);
    imprimeChar(temp,aux1);
}