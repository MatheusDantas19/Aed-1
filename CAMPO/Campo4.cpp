#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 100
#define M 100
using namespace std;
int contClick=0;
int contalgo=0;
//Alunos:Matheus Inacio e Felipe Costa
void iniciaComSpace(char campoPrincipal[N][M],int nlinha,int ncoluna);
void colocaBombas(char campoPrincipal[N][M],int nlinha,int ncoluna,int nbombas);
void clonaCampoPrincipalParacampoAuxiliar(char campoPrincipal[N][N],char campoAuxiliar[N][M],int nlinha,int ncoluna);
void checaVizinhasAoRedor(char campoPrincipal[M][N], char campoAuxiliar[M][N], int linha, int coluna);
void copiaCampoAuxiliarParacampoPrincipal(char campoPrincipal[N][N],char campoAuxiliar[N][M],int nlinha,int ncoluna);
void imprimeCampoPrincipal(char campoPrincipal[N][M],int nlinha,int ncoluna);
void abreCampoVazios (char campoPrincipal[N][M],char campoAuxiliar[N][M],int cordA, int cordB);

int main(){
    int nlinha,ncoluna,nbombas,cordA,cordB,clicksTowin,clicksPlayer;
    char c;
    bool gameOver=false,bandeiraRepetida=false,bandeira=false;
    bool bandeiraNaBomba=false,perdeu=false;
    char* b = (char* )malloc(sizeof(char)*10);
    string z;
    cout<<"Informe quantidade de linhas e colunas: "<<endl;
    cin>>nlinha>>ncoluna;
    if(ncoluna>52){
        ncoluna=52;
    }
    cout<<"Digite a quantidades de bombas "<<"(menor ou igual a "<<nlinha*ncoluna<<")"<<endl;
    cin>>nbombas;
    char campoPrincipal[N][M],campoAuxiliar[N][M];
    clicksTowin=(ncoluna*nlinha)-nbombas;
    iniciaComSpace(campoPrincipal,nlinha,ncoluna);
    colocaBombas(campoPrincipal,nlinha,ncoluna,nbombas);
    clonaCampoPrincipalParacampoAuxiliar(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    checaVizinhasAoRedor(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    copiaCampoAuxiliarParacampoPrincipal(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    iniciaComSpace(campoAuxiliar,nlinha,ncoluna);
   	//imprimeCampoPrincipal(campoPrincipal,nlinha,ncoluna);
    imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
  
    while(gameOver==false){     
    	z="\0";
    	cordA=0;
        cout<<"Coordenada da linha e da Coordenada da Coluna (b1,A ou 1,A): ";
        cin>>b;
        int tam=strlen(b);
        int x,cont=0,i=0,j=0,k=0;
        bandeira=false;
        bandeiraRepetida=false;
        if(b[0]=='b'){
      		bandeira=true;
		}else{
			bandeira=false;
		}
		if(bandeira==true){
			for (i = 1; i < tam,b[i]!=','; i++){
				z+=b[i];
			}
			i++;
			x=atoi(z.c_str());
			cordA=x;
			for(i;i<tam;i++){
				c=b[i];
			}
		}else{
			for (i = 0; i < tam,b[i]!=','; i++){
				z+=b[i];
			}
			i++;
			x=atoi(z.c_str());
			cordA=x;
			for(i;i<tam;i++){
				c=b[i];
			}
		}
        if(c>90){
            cordB=c-96;
            cordB=cordB+26;
        }else{
            cordB=c-64;
        }
        cordB--;
        cordA--;
        if(campoAuxiliar[cordA][cordB]=='b'){
        	bandeiraRepetida=true;
        }
        if(campoAuxiliar[cordA][cordB]!=' ' && bandeiraRepetida==false){
            cout<<"Coordenada já usada, ou Coordenada está fora do Padrão Certo!!!";
        }else{
            if(campoPrincipal[cordA][cordB]==' ' && bandeira==false){
            	abreCampoVazios(campoPrincipal,campoAuxiliar,cordA,cordB);
            	//imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
            	for(int i=0;i<nlinha;i++){
            		for(int j=0;j<ncoluna;j++){
            			if(campoAuxiliar[i][j]=='_' && campoPrincipal[i][j]!='*' && campoPrincipal[i][j]!=' '){
            				campoAuxiliar[i][j]=campoPrincipal[i][j];
            				contClick++;
            			}
            			if(campoAuxiliar[i][j]=='_' && campoPrincipal[i][j]=='*'){
            				campoAuxiliar[i][j]=' ';
            				contClick--;
            			}
            		}
            	}
            	//cout<<contalgo<<endl;
            	//cout<<contClick<<endl;
            	contClick+=contalgo;
            	//cout<<contClick;    
            }else{
            	if(bandeira==true && bandeiraRepetida==false){
            		campoAuxiliar[cordA][cordB]='b';
            		clicksPlayer--;
            	}else{
            		if(campoAuxiliar[cordA][cordB]=='b'){
            			if(bandeira==false){
            				campoAuxiliar[cordA][cordB]=campoPrincipal[cordA][cordB];
            			}else{
            				campoAuxiliar[cordA][cordB]=' ';
            				bandeiraNaBomba=true;
            				clicksPlayer--;
            			}          			
            		}else{
            			campoAuxiliar[cordA][cordB]=campoPrincipal[cordA][cordB];
            		}
            	}
            }
            if(contClick>0){
            	clicksPlayer+=contClick;
            }else{
            	clicksPlayer++;
            }
            
        }
        system("clear");
        //imprimeCampoPrincipal(campoPrincipal,nlinha,ncoluna);
        
        cout<<"\n\n";
        cout<<"Quantidades de bombas: "<<nbombas<<endl;
        imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
        //if(campoAuxiliar[cordA][cordB]==' ' && campoPrincipal[cordA][cordB]=='*'){
      //  	clicksPlayer--;
        //}
        cout<<clicksTowin<<"=="<<clicksPlayer<<endl;
        if(campoPrincipal[cordA][cordB]=='*' && bandeiraNaBomba==false){
        	perdeu=true;
  			if(campoAuxiliar[cordA][cordB]=='b'){
  				bandeiraNaBomba=true;
  			}
  			if(bandeira==false && perdeu==true){
            	for(int i=0;i<nlinha;i++){
                	for(int j=0;j<ncoluna;j++){
                    	if(campoPrincipal[i][j]=='*'){
                        	campoAuxiliar[i][j]=campoPrincipal[i][j];
                    	}
                	}
            	}
  			}
  			if(bandeiraNaBomba==false && perdeu==true){
  				imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
            	gameOver=true;
            	cout<<"\nVocê Perdeu!!!!!!"<<endl;
            	break;
  			}
        }
         if(clicksPlayer==clicksTowin){
         	imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
            cout<<"\nVocê Ganhouu!!!!!"<<endl;
            gameOver=true;
            break;
            //imprimeCampoPrincipal(campoPrincipal,nlinha,ncoluna);

        }
        bandeiraNaBomba=false;
        contClick=0;
        contalgo=0;       	
    }
    free(b);
}

void iniciaComSpace(char campoPrincipal[N][M],int nlinha,int ncoluna){
    for(int i=0;i<nlinha;i++){
        for(int j=0;j<ncoluna;j++){
            campoPrincipal[i][j]=' ';
        }
    }
}

void colocaBombas(char campoPrincipal[N][M],int nlinha,int ncoluna,int nbombas){
    int cont = 0;
        srand(time(NULL));

    while( cont < nbombas ){
        int i = rand() % nlinha ;
        int j = rand() % ncoluna;
        if (campoPrincipal[i][j] == ' '){
            campoPrincipal[i][j] = '*';
            cont++;
        }
    }
}

void clonaCampoPrincipalParacampoAuxiliar(char campoPrincipal[N][N],char campoAuxiliar[N][M],int nlinha,int ncoluna){
    for(int i=0;i<nlinha;i++){
        for(int j=0;j<ncoluna;j++){
            campoAuxiliar[i][j]=campoPrincipal[i][j];
        }
    }
}

void checaVizinhasAoRedor(char campoPrincipal[M][N], char campoAuxiliar[M][N], int linha, int coluna){
    int soma = 0;
    for( int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if ( j > 0 && campoPrincipal[i][j-1] =='*'){
                soma++;
            }
            if ( j < coluna && campoPrincipal[i][j+1] == '*'){
                soma++;
            }
            if ( i < linha && campoPrincipal[i+1][j] == '*'){
                soma++;
            }
            if ( i > 0 && campoPrincipal[i-1][j] == '*'){ 
                soma++;
            }
            if ( i < linha && j>0 && campoPrincipal[i+1][j-1] == '*'){ 
                soma++;
            }
            if ( i < linha && j < coluna && campoPrincipal[i+1][j+1] == '*' ){
                soma++;
            }
            if ( i > 0 && j > 0 && campoPrincipal[i-1][j-1] == '*'){
                soma++;
            }
            if ( i > 0 && j < linha && campoPrincipal[i-1][j+1] == '*'){
                soma++;
            }
            if ( i > 0 && j >0 && campoPrincipal[i-1][j+1] == '*' && soma==0){
                soma++;
            }
            campoAuxiliar[i][j] = soma+'0';
            if(campoAuxiliar[i][j]=='0'){
                campoAuxiliar[i][j]=' ';
            }
            soma = 0;
        }
    }
}

void copiaCampoAuxiliarParacampoPrincipal(char campoPrincipal[N][N],char campoAuxiliar[N][M],int nlinha,int ncoluna){
    for(int i=0;i<nlinha;i++){
        for(int j=0;j<ncoluna;j++){
            if(campoPrincipal[i][j]=='*'){
                continue;
            }else{
                campoPrincipal[i][j]=campoAuxiliar[i][j];
            }
        }
    }
} 

void imprimeCampoPrincipal(char campoPrincipal[N][M],int nlinha,int ncoluna){
    cout<<"\n";
    int inicioLin = 0, finalLin = inicioLin+1,numLin = nlinha, numCol = ncoluna;
    char letra[ncoluna];
    cout<<"   ";

    if(ncoluna>26){
        for(int j=0;j<26;j++){
            letra[j]=j+'0';
            letra[j]=letra[j]+17;
            cout<<letra[j]<<" ";
        }
        for(int j=0;j<(ncoluna-26);j++){
            letra[j]=j+'0';
            letra[j]=letra[j]+49;
            cout<<letra[j]<<" ";
        }
    }else{
        for(int j=0;j<ncoluna;j++){
            letra[j]=j+'0';
            letra[j]=letra[j]+17;
            cout<<letra[j]<<" ";
        }
    }
    cout<<"\n";
    while (inicioLin < numLin) {
        for (int i = inicioLin; i < finalLin; i++) {
            for (int j = 0; j < numCol; j++) {
                if (i == 0 && j == 0) {
                    cout << "  ┌─";
                }
                if (i == 0 && j >= 0 && j <= numCol - 2) {
                    cout << "┬─";
                }
                if (i == 0 && j == numCol - 1) {
                    cout << "┐";
                }
            }
        }
        cout << endl;
        for (int i = inicioLin; i < finalLin; i++) {
            if(i<=8){
                cout<<i+1<<" ";
            }else{
                cout<<i+1<<"";
            }
            for (int j = 0; j < numCol; j++) {
                cout << "│" << campoPrincipal[i][j];
                if (j == numCol - 1) {
                    cout << "│";
                }
            }
        }
        cout << endl;
        for (int i = inicioLin; i < finalLin; i++) {
            for (int j = 0; j < numCol; j++) {
               if (i >= 0&&i<=numLin-2 && j == 0) {
                    cout << "  ├";
               }
               if (i >= 0 && i <= numLin - 2 && j >= 0 && j <= numCol - 2) {
                    cout << "─┼";
               }
               if (i >= 0 && i <= numLin - 2 && j == numCol - 1) {
                    cout << "─┤";
               }
               if (i == (numLin - 1) && j == 0) {
                    cout << "  └─";
               }
                    if (i == (numLin - 1) && j == (numCol-1)) {
                    cout << "┘";
               }
                    if (i == (numLin - 1)&&j>=0 && j < (numCol-1)) {
                    cout << "┴─";
               }
            }
        }
        inicioLin++;
        finalLin=inicioLin+1;
    }
    cout<<"\n";
}

void abreCampoVazios (char campoPrincipal[N][M],char campoAuxiliar[N][M],int cordA, int cordB){
   int x,y;
   bool continua;
   do{
      for (x = cordA - 1; x <= cordA + 1; x++)
         for (y = cordB - 1; y <= cordB + 1; y++){
            continua = false;
            if (campoAuxiliar[x][y] != '_' && campoAuxiliar[x][y]!='1'&& campoAuxiliar[x][y]!='2'
            	&& campoAuxiliar[x][y]!='3'&& campoAuxiliar[x][y]!='4'&& campoAuxiliar[x][y]!='5'
            	&& campoAuxiliar[x][y]!='6'&& campoAuxiliar[x][y]!='7'&& campoAuxiliar[x][y]!='8'&& campoAuxiliar[x][y]!='*'){
               continua = true;
               campoAuxiliar[x][y] = '_';
               if (campoPrincipal[x][y] == ' ' ){
               	contalgo++;
                abreCampoVazios(campoPrincipal,campoAuxiliar,x,y);
               }
            }
         }
   }while(continua);
}