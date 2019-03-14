//Alunos: Matheus Inacio e Felipe Costa
#include <iostream>
#include <string.h>
using namespace std;
void removeEspeciais(char frasePrincipal[], char temp[]){
    int n=strlen(frasePrincipal);
    int i,j;
    for(i=0,j=0;i<n;i++){
        if((frasePrincipal[i] >=32 && frasePrincipal[i]<=34 )  
        || (frasePrincipal[i] >=39 && frasePrincipal[i]<=41 )
        ||(frasePrincipal[i] ==44 || frasePrincipal[i]==46 ) 
        || (frasePrincipal[i] >=48 && frasePrincipal[i]<=59 ) 
        || (frasePrincipal[i] >=65 && frasePrincipal[i]<=90 )
        || (frasePrincipal[i] >=97 && frasePrincipal[i]<=122 )
		  ||(frasePrincipal[i]==63))
            
            {
                temp[j]=frasePrincipal[i];
            }else{
                continue;
            }
            j++;
    }
	frasePrincipal[i]='\0';
    temp[j]='\0';
    cout<<frasePrincipal<<endl;
}

void removEspacos(char temp[], char frasePrincipal[]){
    int m = strlen(temp);
    int cont=0,i,j;
    for(j=0,i=0;j<m;j++){
        if(temp[j]==32){
            if(temp[j+1]==32){
                cont++;
            }
            else{
                frasePrincipal[i]=temp[j];   
            }
        }else{
            frasePrincipal[i]=temp[j];
        }
        if(isspace(temp[j])&&isspace(temp[j+1])){
            cont++;
            if(cont>=1){
                continue;
            }else{
                frasePrincipal[i]=temp[j]; 
            }
        }
        i++;
    }
    frasePrincipal[i]='\0';
    temp[j]='\0';
    cout<<frasePrincipal<<endl;
}

void removePalNum(char frasePrincipal[],char temp[]){
	int n=0,i=0,j=0,p=0,cont=0,cont2=0,acum=0,acum2=0,cont3=0,acum3=0;
	n=strlen(frasePrincipal);
	for(i=0;i<n;i++){
		if((frasePrincipal[acum2]==34 )||(frasePrincipal[acum2]==33)  
        	|| (frasePrincipal[acum2] >=39 && frasePrincipal[acum2]<=41 )
        	||(frasePrincipal[acum2] ==44 || frasePrincipal[acum2]==46 ) 
		 	||(frasePrincipal[acum2]==63)){
			cont++;
		}
		if(frasePrincipal[acum2]>=48 && frasePrincipal[acum2]<=57){
			cont++;
		}
		if((frasePrincipal[i]>=65 && frasePrincipal[i]<=90) || (frasePrincipal[i]>=97 && frasePrincipal[i]<=122)){
			cont2++;
			if(frasePrincipal[i+1]>=48 && frasePrincipal[i+1]<=57){
				cont3++;
			}
		}
		if((frasePrincipal[i]==32) || (i==n-1)){
			cout<<acum<<endl;
			cout<<cont<<endl;
			cout<<cont2<<endl;
			cout<<cont3<<endl;
			if(cont>=1 && acum>=0){
				for(j=acum2;j<i+1;j++){
					temp[p]=frasePrincipal[j];
					p++;
				}
				acum=0;
			}else{
				if(cont2>0 && cont3==0 && acum>=0){
					for(j=acum2;j<i+1;j++){
						temp[p]=frasePrincipal[j];
						p++;
					}
				}
				acum=0;
			}
			acum2=i+1;
			cont=0;
			cont2=0;
			cont3=0;
			acum=0;
		}
	}
	temp[p]='\0';
	cout<<temp<<endl;
}

void removerRepetidos(char temp[],char frasePrincipal[]){
	int n=0,i=0,j=0,p=0,cont=0;
	n=strlen(temp);
	for(i=0;i<n;i++){
		cont=0;
		if((frasePrincipal[i]==34 )||(frasePrincipal[i]==33)  
        	|| (frasePrincipal[i] >=39 && frasePrincipal[i]<=41 )
        	||(frasePrincipal[i] ==44 || frasePrincipal[i]==46 ) 
        	|| (frasePrincipal[i] >=48 && frasePrincipal[i]<=59 )
		 	||(frasePrincipal[i]==63)){
			frasePrincipal[p]=temp[i];
		}else{
			if(temp[i]==temp[i]){
            	if(temp[i+1]==temp[i]){
              		if(temp[i+2]==temp[i]){
              		cont++;
              		}
            	}
            	else{
                	frasePrincipal[p]=temp[i];   
           		}
        	}else{
            	frasePrincipal[p]=temp[i];
        	}
       		if(cont>=1){
        		continue;
        	}else{
        		frasePrincipal[p]=temp[i];
        	}
		}
		
        p++;
	}
	frasePrincipal[p]='\0';
	cout<<frasePrincipal<<endl;
}

void fechaParentsEAspas(char frase[],char aux[]){
	int parCont=0,aspasCont=0,cont=0;
	bool addParenteses=false;
	bool addAspas=false,aspasAberto=false;
	for(cont=0;cont<strlen(frase);cont++){
		//verifica quantos parenteses precisam ser fechados;
		if(frase[cont]==40)
			parCont++;		
		
		if(frase[cont]==41)
			parCont--;
		
		if((frase[cont]==46)&&(parCont>0))
			addParenteses=true;
		
	//verifica quantas aspas precisam ser fechadas;
		if(frase[cont]==34 && aspasAberto==true){
			aspasCont--;
			aspasAberto=false;
		}else{
			if(frase[cont]==34 && aspasAberto==false){
				aspasCont++;
				aspasAberto=true;
			}
		}
				
		if((frase[cont]==46)&&(aspasCont>0)&&(aspasAberto==true))
			addAspas=true;
		
	}
	//adiciona os parenteses restantes
	if(addParenteses==true){
		for(cont=0;cont<parCont;cont++){
			aux[cont]=41;
		}
		strcat(frase,aux);
	}
	//adiciona as aspas restantes
	if(addAspas==true){
		for(cont=0;cont<aspasCont;cont++){
			aux[cont]=34;
		}
		strcat(frase,aux);
	}
	
}


void imprimeChar(char frasePrincipal[]){
    cout<<"\n";
    cout<<"Versão limpa: "<<endl;
    cout<<frasePrincipal<<endl;
}
int main(){
    char frasePrincipal[1000];
    char temp[1000];
	
	cout<<"Digite a frase: "<<endl;
    cin.getline(frasePrincipal,500);
  	removeEspeciais(frasePrincipal,temp);
    removEspacos(temp,frasePrincipal);
    
    removePalNum(frasePrincipal,temp);
    removerRepetidos(temp,frasePrincipal);
    fechaParentsEAspas(frasePrincipal,temp);
    

  
	
	imprimeChar(frasePrincipal);
}