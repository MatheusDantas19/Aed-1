//Alunos: Matheus Inacio e Felipe Costa
#include <iostream>
#include <string.h>
using namespace std;
void removeEspeciais(char aux[], char temp[]){
    int n=strlen(aux);
    int i,j;
    for(i=0,j=0;i<n;i++){
        if((aux[i] ==32 || aux[i]==34 ) 
        || (aux[i] ==33 || aux[i]==63 ) 
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
        cout<<"\n";
    cout<<"Versão limpa Sem Especiais: "<<endl;
    cout<<temp<<endl;

}
void removEspacos(char temp[], char aux[]){
    int m = strlen(temp);
    int cont=0,i,j;
    for(j=0,i=0;j<m;j++){
  
        if(temp[j]==32){
            if(temp[j+1]==32){
                cont++;
            }
            else{
                aux[i]=temp[j];   
            }
        }else{
            aux[i]=temp[j];
        }
        if(isspace(temp[j])&&isspace(temp[j+1])){
            cont++;
            if(cont>=1){
                continue;
            }else{
                aux[i]=temp[j]; 
            }
        }
        i++;
    }
    aux[i]='\0';
    temp[j]='\0';
    cout<<"Versão limpa Sem Espaços: "<<endl;
    cout<<aux<<endl;
}

void removeSequencia(char aux[],char temp[]){
	int n=0,i=0,j=0,k=0,p=0,cont=0,cont2=0,acum=0,acum2=0,cont3=0,acum3=0;
	n=strlen(aux);
	for(i=0;i<n;i++){
        if((aux[i]==34 ) 
        || (aux[i] ==32 || aux[i]==34 ) 
        || (aux[i] >=39 && aux[i]<=41 )
        ||(aux[i] ==44 || aux[i]==46 ) 
        || (aux[i] >=48 && aux[i]<=59 ) 
        || (aux[i] >=65 && aux[i]<=90 )
        || (aux[i] >=97 && aux[i]<=122 ))
            
            {
		if(aux[acum2]>=48 && aux[acum2]<=57){
			cont++;
		}
		if((aux[i]>=65 && aux[i]<=90) || (aux[i]>=97 && aux[i]<=122)){
			cont2++;
			if((aux[i+1]>=48 && aux[i+1]<=57)||(aux[i+2]>=48 && aux[i+2]<=57)){
				cont3++;
			}
		}
		if((aux[i]==32) || (i==n-1)){
            cout<<cont<<endl;
            cout<<cont3<<endl;
			if(cont>=1){
				for(j=acum2;j<i+1;j++){
					temp[p]=aux[j];
					p++;
				}
			}else{
				if(cont2>0 && cont3==0){
					for(j=acum3;j<i+1;j++){
						temp[p]=aux[j];
						p++;
					}
				}
			}
			acum2=i+1;
			cont=0;
			acum3=i+1;
			cont2=0;
			cont3=0;
		}
	}
	temp[p]='\0';
    cout<<"Versão limpa Palavras Com Letras e Numeros: "<<endl;
    cout<<temp<<endl;
}

void removerRepetidos(char temp[],char aux[]){
	int n=0,i=0,j=0,p=0,cont=0;
	n=strlen(temp);
	for(i=0;i<n;i++){
		cont=0;
		if(temp[i]==temp[i+1]){
            if(temp[i+2]==temp[i] || temp[]){
              	if(temp[i+2]==temp[i]){
              		cont++;
              	}
            }
            else{
                aux[p]=temp[i];   
            }
        }else{
            aux[p]=temp[i];
        }
        if(cont>=1){
        	continue;
        }else{
        	aux[p]=temp[i];
        }
        p++;
	}
	aux[p]='\0';
    cout<<"Versão limpa Palavras Com Repetição"<<endl;
    cout<<aux<<endl;
}

/*void imprimeChar(char temp[], char aux1[],char temp2[],char temp3[]){
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
}*/

int main(){
    char aux[1000];
    char temp[1000];
    //char aux1[1000];
    //char temp2[1000];
    //char temp3[1000];
	cout<<"Digite a frase: "<<endl;
    cin.getline(aux,500);

    removeEspeciais(aux,temp);
    removEspacos(temp,aux);
    removeSequencia(aux,temp);
    removerRepetidos(temp,aux);
    //imprimeChar(temp,aux1,temp2,temp3);
	return 0;
}