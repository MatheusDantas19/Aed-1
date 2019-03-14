//Alunos: Matheus Inacio e Felipe Costa
#include <iostream>
#include <string.h>
using namespace std;
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
	aux[i]='\0';
    temp[j]='\0';
}
void removEspacos(char temp[], char aux1[]){
    int m = strlen(temp);
    int cont=0,i,j;
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
}

void removeSequencia(char aux1[],char temp2[]){
	int n=0,i=0,j=0,k=0,p=0,aux,cont=0,cont2=0,acum=0,acum2=0,cont3=0,acum3=0,contc=0;
	n=strlen(aux1);
	for(i=0;i<n;i++){
		if(( aux1[i]==34 ) || (aux1[i] ==39 || aux1[i]==41 )
			|| (aux1[i]==40) ||(aux1[i] ==44 || aux1[i]==46 )
			||(aux1[i]==58)||(aux1[i]==59)){
			contc++;
		}
		if((aux1[acum2]>=48 && aux1[acum2]<=57)||(aux1[acum2+1]>=48 && aux1[acum2+1]<=57)){
			cont++;
		}
		if((aux1[i]>=65 && aux1[i]<=90) || (aux1[i]>=97 && aux1[i]<=122)){
			cont2++;
			if(aux1[i+1]>=48 && aux1[i+1]<=57){
				cont3++;
			}
		}
		if((aux1[i]==32) || (i==n-1)||(aux1[i] ==44) || (aux1[i]==46 )){
			if(contc>=1){
				cout<<contc<<endl;
				if(cont>=1){
					for(j=acum2;j<i+1;j++){
						temp2[p]=aux1[j];
						p++;
					}
			}else{
				if(cont2>0 && cont3==0){
					for(j=acum3;j<i+1;j++){
						temp2[p]=aux1[j];
						p++;
					}
				}
			}
				acum2=i+1;
				cont=0;
				acum3=i+1;
				cont2=0;
				cont3=0;
				contc=0;
		}else{
			if(cont>=1){
				for(j=acum2;j<i+1;j++){
					temp2[p]=aux1[j];
					p++;
				}
			}else{
				if(cont2>0 && cont3==0){
					for(j=acum3;j<i+1;j++){
						temp2[p]=aux1[j];
						p++;
					}
				}
			}
			acum2=i+1;
			cont=0;
			acum3=i+1;
			cont2=0;
			cont3=0;
			contc=0;
		}
	}
			
	}
	temp2[p]='\0';
}

void removerRepetidos(char temp2[],char temp3[]){
	int n=0,i=0,j=0,aux=0,p=0,cont=0;
	n=strlen(temp2);
	for(i=0;i<n;i++){
		cont=0;
		if(temp2[i]==temp2[i]){
            if(temp2[i+1]==temp2[i]){
              	if(temp2[i+2]==temp2[i]){
              		cont++;
              	}
            }
            else{
                temp3[p]=temp2[i];   
            }
        }else{
            temp3[p]=temp2[i];
        }
        if(cont>=1){
        	continue;
        }else{
        	temp3[p]=temp2[i];
        }
        p++;
	}
	temp3[p]='\0';
}

void imprimeChar(char temp[], char aux1[],char temp2[],char temp3[]){
    cout<<"\n";
    cout<<"Versão limpa Sem Especiais: "<<endl;
    cout<<temp<<endl;
    cout<<"\n";
    cout<<"Versão limpa Sem Espaços: "<<endl;
    cout<<aux1<<endl;
    cout<<"\n";
 	cout<<"Versão limpa Palavras Com Letras e Numeros: "<<endl;
	cout<<temp2<<endl;
	cout<<"\n";
	cout<<"Versão limpa Palavras Com Repetição"<<endl;
	cout<<temp3<<endl;
}

int main(){
    char aux[1000];
    char temp[1000];
    char aux1[1000];
    char temp2[1000];
    char temp3[1000];
	cout<<"Digite a frase: "<<endl;
    cin.getline(aux,500);

    removeEspeciais(aux,temp);
    removEspacos(temp,aux1);
    removeSequencia(aux1,temp2);
    removerRepetidos(temp2,temp3);
    imprimeChar(temp,aux1,temp2,temp3);
	return 0;
}