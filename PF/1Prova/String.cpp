#include <iostream>
#include <string.h>
using namespace std;
void Strcpy(char s1[],char s2[]){
    int i,j,aux;
    for(i=0;i<50;i++){
        if(s1[i]=='\0'){
            aux=i;
            for(j=0;s2[j]!='\0';j++){
                s1[aux]=s2[j];
                aux++;
            }
            break;
        }
    }
    s1[aux]='\0';
    cout<<s1<<endl;
}

int Compara(char s1[], char s2[]){
    int tam=strlen(s1);
    int tam2=strlen(s2);
    int cont=0;
    for(int i=0;s1[i]!='\0' && s2[i]!='\0';i++){
        if(s1[i]==s2[i]){
            cont++;
            if(cont==tam-1 && cont==tam2-1){
                return 0;
            }
        }else if (s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1;
    }
}

int Conteudo(char s1[],char s2[]){
    for(int i=0;i<100;i++){
        if(s2[i]==s1[i]){
            if(s1[i+1]=='\0' && s2[i+1]=='\0'){
                return 1;
            }
        }else{
            return 0;
        }
    }
}

void RemoveVogais(char s1[]){
    char aux[strlen(s1)],cont=0;
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]=='a'){

        }else if(s1[i]=='e'){

        }else if(s1[i]=='i'){
            
        }else if(s1[i]=='o'){
            
        }else if(s1[i]=='u'){

        }else{
            aux[cont]=s1[i];
            cont++;
        }
    }
    aux[cont]='\0';
    cout<<aux<<endl;;
}
int main(){
    char s1[50],s2[50];
    cin>>s1;
    cin>>s2;
  //  Strcpy(s1,s2);
    RemoveVogais(s1);
}