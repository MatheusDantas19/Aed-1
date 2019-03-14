#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define N 100
#define M 100
using namespace std;
//Mat=matriz iniciada com espaço
//Mat1=matriz com espaço e bombas

void iniciaComSpace(struct stCelula **campoPrincipal,int nlinha,int ncoluna);
void imprimeCampoComSpace(struct stCelula **campoPrincipal,int nlinha,int ncoluna);
void colocaBombas(struct stCelula **campoPrincipal,int nlinha,int ncoluna,int nbombas);
void clonaCampoPrincipalParacampoAuxiliar(struct stCelula **campoPrincipal,struct stCelula **campoAuxiliar,int nlinha,int ncoluna);
void checa_vizinhas(struct stCelula **campoPrincipal, struct stCelula **campoAuxiliar, int linha, int coluna);
void imprimeCampoVizinha(struct stCelula **campoAuxiliar,int nlinha,int ncoluna);
void copiaCampoAuxiliarParacampoPrincipal(struct stCelula **campoPrincipal,struct stCelula **campoAuxiliar,int nlinha,int ncoluna);
void imprimeCampoPrincipal(struct stCelula **campoPrincipal,int nlinha,int ncoluna);
struct stCelula
{
	bool bandeira;
	bool nova;
	int bombasRedor;
	char conteudo;
};
int main()
{
    int nlinha,ncoluna,nbombas,cordA,cordB;
    cout<<"Digite a quantidade de Linhas e a quantidade de Colunas da Matriz: "<<endl;
    cin>>nlinha>>ncoluna;
    cout<<"Digite a quantidades de bombas "<<"(menor ou igual a "<<nlinha*ncoluna<<")"<<endl;
    cin>>nbombas;
    
	struct stCelula **campoPrincipal,**campoAuxiliar;


	campoPrincipal=(struct stCelula **)malloc(nlinha *(sizeof(struct stCelula*)));
	campoAuxiliar =(struct stCelula **)malloc(nlinha *(sizeof(struct stCelula*)));
    
	for (int i=0; i<nlinha; i++)
    {
		campoPrincipal[i]=(struct stCelula*)malloc(ncoluna *(sizeof(struct stCelula)));
		campoAuxiliar [i]=(struct stCelula*)malloc(ncoluna *(sizeof(struct stCelula)));
	}
	iniciaComSpace(campoPrincipal,nlinha,ncoluna);
    imprimeCampoComSpace(campoPrincipal,nlinha,ncoluna);
    colocaBombas(campoPrincipal,nlinha,ncoluna,nbombas);
    clonaCampoPrincipalParacampoAuxiliar(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    checa_vizinhas(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    copiaCampoAuxiliarParacampoPrincipal(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    imprimeCampoVizinha(campoAuxiliar,nlinha,ncoluna);
    imprimeCampoPrincipal(campoPrincipal,nlinha,ncoluna);
    free(campoAuxiliar);
    free(campoPrincipal);
}

void iniciaComSpace(struct stCelula **campoPrincipal,int nlinha,int ncoluna)
{
    for(int i=0;i<nlinha;i++)
	{
        for(int j=0;j<ncoluna;j++)
		{
            campoPrincipal[i][j].conteudo = ' ';
        }
    }
}
void imprimeCampoComSpace(struct stCelula **campoPrincipal,int nlinha,int ncoluna)
{
    cout<<"\n"<<"Tabuleiro Fechado:"<<endl;
    int inicioLin = 0, finalLin = inicioLin+1,numLin = nlinha, numCol = ncoluna;;
    while (inicioLin < numLin) 
	{
        for (int i = inicioLin; i < finalLin; i++) 
		{
            for (int j = 0; j < numCol; j++) 
			{
                if (i == 0 && j == 0) {
                    cout << "┌─";
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
        for (int i = inicioLin; i < finalLin; i++)
			{
            for (int j = 0; j < numCol; j++) 
			{
                cout << "│" << campoPrincipal[i][j].conteudo;
                if (j == numCol - 1) {
                    cout << "│";
                }
            }
            
        }
        cout << endl;
        for (int i = inicioLin; i < finalLin; i++) 
		{
            for (int j = 0; j < numCol; j++) 
			{
               if (i >= 0&&i<=numLin-2 && j == 0) {
                    cout << "├";
               }
               if (i >= 0 && i <= numLin - 2 && j >= 0 && j <= numCol - 2) {
                    cout << "─┼";
               }
               if (i >= 0 && i <= numLin - 2 && j == numCol - 1) {
                    cout << "─┤";
               }
               if (i == (numLin - 1) && j == 0) {
                    cout << "└─";
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
}
void colocaBombas(struct stCelula **campoPrincipal,int nlinha,int ncoluna,int nbombas)
{
    int cont = 0;
    while( cont < nbombas ){
        int i = rand() % nlinha ;
        int j = rand() % ncoluna;
        if (campoPrincipal[i][j].conteudo == ' ')
		{
            campoPrincipal[i][j].conteudo = '*';
            cont++;
        }
    }
}

void clonaCampoPrincipalParacampoAuxiliar(struct stCelula **campoPrincipal,struct stCelula **campoAuxiliar,int nlinha,int ncoluna)
{
    for(int i=0;i<nlinha;i++)
	{
        for(int j=0;j<ncoluna;j++)
		{
            campoAuxiliar[i][j].conteudo=campoPrincipal[i][j].conteudo;
			campoAuxiliar[i][j].bandeira=campoPrincipal[i][j].bandeira;
			campoAuxiliar[i][j].nova=campoPrincipal[i][j].nova;
			campoAuxiliar[i][j].bombasRedor=campoPrincipal[i][j].bombasRedor;
        }
    }
}

void checa_vizinhas(struct stCelula **campoPrincipal, struct stCelula **campoAuxiliar, int linha, int coluna){
    int soma = 0;
    for( int i = 0; i < linha; i++){
    	for (int j = 0; j < coluna; j++){
    		if ( j > 0 && campoPrincipal[i][j-1].conteudo =='*'){
    			soma++;
            }
            if ( j < coluna && campoPrincipal[i][j+1].conteudo == '*'){
             	soma++;
            }
            if ( i < linha && campoPrincipal[i+1][j].conteudo == '*'){
            	soma++;
            }
            if ( i > 0 && campoPrincipal[i-1][j].conteudo == '*'){ 
             	soma++;
            }
            if ( i < linha && j>0 && campoPrincipal[i+1][j-1].conteudo == '*'){ 
          	 	soma++;
            }
            if ( i < linha && j < coluna && campoPrincipal[i+1][j+1].conteudo == '*' ){
              	soma++;
            }
            if ( i > 0 && j > 0 && campoPrincipal[i-1][j-1].conteudo == '*'){
               	soma++;
           	}
            if ( i > 0 && j < linha && campoPrincipal[i-1][j+1].conteudo == '*'){
               	soma++;
            }
            campoAuxiliar[i][j].bombasRedor = soma;
            if(campoAuxiliar[i][j].bombasRedor==0){
                campoAuxiliar[i][j].conteudo=' ';
            }
            soma = 0;
        }
	}
}
void imprimeCampoVizinha(struct stCelula **campoAuxiliar,int nlinha,int ncoluna){
    cout<<"\n"<<"Tabuleiro Vizinho:"<<endl;
    int inicioLin = 0, finalLin = inicioLin+1,numLin = nlinha, numCol = ncoluna;
    while (inicioLin < numLin) {
        for (int i = inicioLin; i < finalLin; i++) {
            for (int j = 0; j < numCol; j++) {
                if (i == 0 && j == 0) {
                    cout << "┌─";
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
            for (int j = 0; j < numCol; j++) {
                cout << "│" << campoAuxiliar[i][j].conteudo;
                if (j == numCol - 1) {
                    cout << "│";
                }
            }
            
        }
        cout << endl;
        for (int i = inicioLin; i < finalLin; i++) {
            for (int j = 0; j < numCol; j++) {
               if (i >= 0&&i<=numLin-2 && j == 0) {
                    cout << "├";
               }
               if (i >= 0 && i <= numLin - 2 && j >= 0 && j <= numCol - 2) {
                    cout << "─┼";
               }
               if (i >= 0 && i <= numLin - 2 && j == numCol - 1) {
                    cout << "─┤";
               }
               if (i == (numLin - 1) && j == 0) {
                    cout << "└─";
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
}

void copiaCampoAuxiliarParacampoPrincipal(struct stCelula **campoPrincipal,struct stCelula **campoAuxiliar,int nlinha,int ncoluna){
    for(int i=0;i<nlinha;i++){
        for(int j=0;j<ncoluna;j++){
        	if(campoPrincipal[i][j].conteudo=='*'){
            	continue;
        	}else{
        		campoPrincipal[i][j].conteudo=campoAuxiliar[i][j].conteudo;
        	}
        }
    }
} 

void imprimeCampoPrincipal(struct stCelula **campoPrincipal,int nlinha,int ncoluna){
    cout<<"\n"<<"Tabuleiro Final:"<<endl;
    int inicioLin = 0, finalLin = inicioLin+1,numLin = nlinha, numCol = ncoluna;
    while (inicioLin < numLin) {
        for (int i = inicioLin; i < finalLin; i++) {
            for (int j = 0; j < numCol; j++) {
                if (i == 0 && j == 0) {
                    cout << "┌─";
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
            for (int j = 0; j < numCol; j++) {
                cout << "│" << campoPrincipal[i][j].conteudo;
                if (j == numCol - 1) {
                    cout << "│";
                }
            }
            
        }
        cout << endl;
        for (int i = inicioLin; i < finalLin; i++) {
            for (int j = 0; j < numCol; j++) {
               if (i >= 0&&i<=numLin-2 && j == 0) {
                    cout << "├";
               }
               if (i >= 0 && i <= numLin - 2 && j >= 0 && j <= numCol - 2) {
                    cout << "─┼";
               }
               if (i >= 0 && i <= numLin - 2 && j == numCol - 1) {
                    cout << "─┤";
               }
               if (i == (numLin - 1) && j == 0) {
                    cout << "└─";
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