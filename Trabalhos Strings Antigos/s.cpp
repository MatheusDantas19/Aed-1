//Alunos: Matheus Inacio e Felipe Costa
#include <iostream>
#include <string.h>
using namespace std;
void removeEspeciais(char frasePrincipal[], char fraseAuxiliar[]){
    int i=0,j=0;
    for(i=0;i<strlen(frasePrincipal);i++){
        if((frasePrincipal[i] >=32 && frasePrincipal[i]<=34 )  
        || (frasePrincipal[i] >=39 && frasePrincipal[i]<=41 )
        ||(frasePrincipal[i] ==44 || frasePrincipal[i]==46 ) 
        || (frasePrincipal[i] >=48 && frasePrincipal[i]<=59 ) 
        || (frasePrincipal[i] >=65 && frasePrincipal[i]<=90 )
        || (frasePrincipal[i] >=97 && frasePrincipal[i]<=122 )
		||(frasePrincipal[i]==63)){
            fraseAuxiliar[j]=frasePrincipal[i];
        }else{
            continue;
        }
        j++;
    }
	frasePrincipal[i]='\0';
    fraseAuxiliar[j]='\0';
}

void removEspacos(char fraseAuxiliar[], char frasePrincipal[]){
    int contEspaco=0,i=0,j=0;
    for(i=0;i<strlen(fraseAuxiliar);i++){
        if(fraseAuxiliar[i]==32){
            if(fraseAuxiliar[i+1]==32){
                contEspaco++;
            }else{
                frasePrincipal[j]=fraseAuxiliar[i];   
            }
        }else{
            frasePrincipal[j]=fraseAuxiliar[i];
        }
        if(isspace(fraseAuxiliar[i])&&isspace(fraseAuxiliar[i+1])){
            contEspaco++;
            if(contEspaco>=1){
                continue;
            }else{
                frasePrincipal[j]=fraseAuxiliar[i]; 
            }
        }
        j++;
    }
    frasePrincipal[j]='\0';
    fraseAuxiliar[i]='\0';
}

void removePalNum(char frasePrincipal[],char fraseAuxiliar[]){
	int n=0,i=0,j=0,p=0,contCharNum=0,contLetras=0,contCharEspecial=0;
	int novaPosicao=0,contSequenciaLetraNum=0,posicaoCharEspecial=0;
	for(i=0;i<strlen(frasePrincipal);i++){
		if((frasePrincipal[novaPosicao]==34 )||(frasePrincipal[novaPosicao]==33)  
        || (frasePrincipal[novaPosicao] >=39 && frasePrincipal[novaPosicao]<=41 )
        ||(frasePrincipal[novaPosicao] ==44 || frasePrincipal[novaPosicao]==46 ) 
		||(frasePrincipal[novaPosicao]==63)){
			contCharNum++;
		}
		if(frasePrincipal[novaPosicao]>=48 && frasePrincipal[novaPosicao]<=57){
			contCharNum++;
		}
		if((frasePrincipal[i]>=65 && frasePrincipal[i]<=90) 
		|| (frasePrincipal[i]>=97 && frasePrincipal[i]<=122)){
			contLetras++;
			if(frasePrincipal[i+1]>=48 && frasePrincipal[i+1]<=57){
				contSequenciaLetraNum++;
			}
		}
		if((frasePrincipal[i]==32) || (i==n-1) || (frasePrincipal[i]==34)
		||(frasePrincipal[i]==44)||(frasePrincipal[i]==46)||(frasePrincipal[i]==58)
		||(frasePrincipal[i]==59)||(frasePrincipal[i]==33)||(frasePrincipal[i]==63)){
			if((frasePrincipal[i]==34)
			||(frasePrincipal[i]==44)||(frasePrincipal[i]==46)||(frasePrincipal[i]==58)
			||(frasePrincipal[i]==59)||(frasePrincipal[i]==33)||(frasePrincipal[i]==63)){
				contCharEspecial++;
				posicaoCharEspecial=i;
			}
			if(contCharNum>=1 && posicaoCharEspecial>=0){
				for(j=novaPosicao;j<i+1;j++){
					fraseAuxiliar[p]=frasePrincipal[j];
					p++;
				}
			}else{
				if(contLetras>0 && contSequenciaLetraNum==0){
					for(j=novaPosicao;j<i+1;j++){
						fraseAuxiliar[p]=frasePrincipal[j];
						p++;
					}
				}else if(contLetras>0 && contSequenciaLetraNum>0 && posicaoCharEspecial>0){
					for(j=posicaoCharEspecial;j<i+1;j++){
						fraseAuxiliar[p]=frasePrincipal[j];
						p++;
					}
				}
			}
			novaPosicao=i+1;
			contCharNum=0;
			contLetras=0;
			contSequenciaLetraNum=0;
			posicaoCharEspecial=0;
			contCharEspecial=0;
		}
	}
	fraseAuxiliar[p]='\0';
}

void removerRepetidos(char fraseAuxiliar[],char frasePrincipal[]){
	int i=0,p=0,contRepetido=0;
	for(i=0;i<strlen(fraseAuxiliar);i++){
		contRepetido=0;
		if((fraseAuxiliar[i]==34 )||(fraseAuxiliar[i]==33)  
        || (fraseAuxiliar[i] >=39 && fraseAuxiliar[i]<=41 )
        ||(fraseAuxiliar[i] ==44 || fraseAuxiliar[i]==46 ) 
        || (fraseAuxiliar[i] >=48 && fraseAuxiliar[i]<=59 )
		||(fraseAuxiliar[i]==63)||(fraseAuxiliar[i]==63)){
			frasePrincipal[p]=fraseAuxiliar[i];
		}else{
			if(fraseAuxiliar[i]==fraseAuxiliar[i+1]){
            	if(fraseAuxiliar[i+2]==fraseAuxiliar[i]){
            		contRepetido++;	
            	}else{
                	frasePrincipal[p]=fraseAuxiliar[i];   
           		}
        	}else{
            	frasePrincipal[p]=fraseAuxiliar[i];
        	}
       		if(contRepetido>=1){
        		continue;
        	}else{
        		frasePrincipal[p]=fraseAuxiliar[i];
        	}
		}
        p++;
	}
	frasePrincipal[p]='\0';
}

void fechaAspas(char frasePrincipal[],char fraseAuxiliar[]){
	int aspasCont=0,cont=0;
	bool addAspas=false,aspasAberto=false;
	for(cont=0;cont<strlen(frasePrincipal);cont++){
		//verifica quantas aspas precisam ser fechadas;
		if(frasePrincipal[cont]==34 && aspasAberto==true){
			aspasCont--;
			aspasAberto=false;
		}else{
			if(frasePrincipal[cont]==34 && aspasAberto==false){
				aspasCont++;
				aspasAberto=true;
			}
		}
		if((frasePrincipal[cont]==46)&&(aspasCont>0)&&(aspasAberto==true)){
			addAspas=true;
		}
	}
	fraseAuxiliar[0]='\0';
	//adiciona os aspas restantes
	if(addAspas==true){
		for(cont=0;cont<aspasCont;cont++){
			fraseAuxiliar[cont]=34;
		}
		fraseAuxiliar[cont]='\0';
		strcat(frasePrincipal,fraseAuxiliar);
   	}
}
	
void fechaParenteses(char frasePrincipal[],char fraseAuxiliar[]){
	int parCont=0,cont=0;
	bool addParenteses=false;
	for(cont=0;cont<strlen(frasePrincipal);cont++){
		//verifica quantos parenteses precisam ser fechados;
		if(frasePrincipal[cont]==40){
			parCont++;		
		}
		if(frasePrincipal[cont]==41){
			parCont--;
		}
		if((frasePrincipal[cont]==46)&&(parCont>0)){
			addParenteses=true;		
		}
	}
	fraseAuxiliar[0]='\0';
	//adiciona os parenteses restantes
	if(addParenteses==true){
		for(cont=0;cont<parCont;cont++){
			fraseAuxiliar[cont]=41;
		}
		fraseAuxiliar[cont]='\0';
		strcat(frasePrincipal,fraseAuxiliar);
	}
}

void imprimeChar(char frasePrincipal[]){
    cout<<"\n";
    cout<<"Versão limpa: "<<endl;
    cout<<frasePrincipal<<endl;
}
	
int main(){
    char frasePrincipal[1000];
    char fraseAuxiliar[1000];
	
	cout<<"Digite a frase: "<<endl;
    cin.getline(frasePrincipal,500);
	
  	removeEspeciais(frasePrincipal,fraseAuxiliar);
    removEspacos(fraseAuxiliar,frasePrincipal);
    removePalNum(frasePrincipal,fraseAuxiliar);
    removerRepetidos(fraseAuxiliar,frasePrincipal);
   	fechaAspas(frasePrincipal,fraseAuxiliar); 
	fechaParenteses(frasePrincipal,fraseAuxiliar);
	imprimeChar(frasePrincipal);
}