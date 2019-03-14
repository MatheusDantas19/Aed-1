#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define N 100
#define M 100
using namespace std;
//Mat=matriz iniciada com espaço
//Mat1=matriz com espaço e bombas
void iniciaComSpace(char campoPrincipal[N][M],int nlinha,int ncoluna);
void imprimeCampoComSpace(char campoPrincipal[N][M],int nlinha,int ncoluna);
void colocaBombas(char campoPrincipal[N][M],int nlinha,int ncoluna,int nbombas);
void clonaCampoPrincipalParacampoAuxiliar(char campoPrincipal[N][N],char campoAuxiliar[N][M],int nlinha,int ncoluna);
void checa_vizinhas(char campoPrincipal[M][N], char campoAuxiliar[M][N], int linha, int coluna);
void imprimeCampoVizinha(char campoAuxiliar[N][M],int nlinha,int ncoluna);
void copiaCampoAuxiliarParacampoPrincipal(char campoPrincipal[N][N],char campoAuxiliar[N][M],int nlinha,int ncoluna);
void imprimeCampoPrincipal(char campoPrincipal[N][M],int nlinha,int ncoluna);


int main(){
    int nlinha,ncoluna,nbombas,cordA,cordB,clicksTowin,clicksPlayer;
    char c;
    char bandeira;
    bool gameOver=false;
    char caracteres[ncoluna];
    cout<<"Digite a Linha e a Coluna da Matriz: "<<endl;
    cin>>nlinha>>ncoluna;
    cout<<"Digite a quantidades de bombas "<<"(menor ou igual a "<<nlinha*ncoluna<<")"<<endl;
    cin>>nbombas;
    char campoPrincipal[N][M],campoAuxiliar[N][M];
    clicksTowin=(ncoluna*nlinha)-nbombas;
    iniciaComSpace(campoPrincipal,nlinha,ncoluna);
    //imprimeCampoComSpace(campoPrincipal,nlinha,ncoluna);
    colocaBombas(campoPrincipal,nlinha,ncoluna,nbombas);
    clonaCampoPrincipalParacampoAuxiliar(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    checa_vizinhas(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    copiaCampoAuxiliarParacampoPrincipal(campoPrincipal,campoAuxiliar,nlinha,ncoluna);
    iniciaComSpace(campoAuxiliar,nlinha,ncoluna);
    //imprimeCampoVizinha(campoAuxiliar,nlinha,ncoluna);
    imprimeCampoPrincipal(campoPrincipal,nlinha,ncoluna);
    imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
    
    while(gameOver==false){     
        cout<<"Coordenada da linha: ";
        cin>>bandeira>>cordA;
        cordA--;
        cout<<"Coordenada da coluna(Diferencie maiúscula/minúscula): ";
        cin>>c;
        cordB=c-64;
        if(cordB>26){
            cordB=c-96;
            cordB=cordB+26;
        }
        cordB--;
        if(campoAuxiliar[cordA][cordB]!=' '){
            cout<<"Coordenada já usada, use outra";
        }else{
            if(campoPrincipal[cordA][cordB]==' '){
                campoAuxiliar[cordA][cordB]='_';
            }else{
                campoAuxiliar[cordA][cordB]=campoPrincipal[cordA][cordB];
            }
            clicksPlayer++;
        }
        imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
        clicksPlayer++;
        if(clicksPlayer==clicksTowin){
            cout<<"Ganhoou muleke doido!!!!!"<<endl;
            gameOver=true;
        }
        if(campoPrincipal[cordA][cordB]=='*'){
            for(int i=0;i<nlinha;i++){
                for(int j=0;j<ncoluna;j++){
                    if(campoPrincipal[i][j]=='*')
                        campoAuxiliar[i][j]=campoPrincipal[i][j];
                }
            }
            imprimeCampoPrincipal(campoAuxiliar,nlinha,ncoluna);
            gameOver=true;
            cout<<"Cê perdeu otário"<<endl;
        }
    }
}


void iniciaComSpace(char campoPrincipal[N][M],int nlinha,int ncoluna){
    for(int i=0;i<nlinha;i++){
        for(int j=0;j<ncoluna;j++){
            campoPrincipal[i][j]=' ';
        }
    }
}
void imprimeCampoComSpace(char campoPrincipal[N][M],int nlinha,int ncoluna){
    cout<<"\n"<<"Tabuleiro Fechado:"<<endl;
    int inicioLin = 0, finalLin = inicioLin+1,numLin = nlinha, numCol = ncoluna;
    int j=0;
    char letra[ncoluna];
    int cont=0;
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
}
void colocaBombas(char campoPrincipal[N][M],int nlinha,int ncoluna,int nbombas){
    int cont = 0;
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

void checa_vizinhas(char campoPrincipal[M][N], char campoAuxiliar[M][N], int linha, int coluna){
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
            campoAuxiliar[i][j] = soma+'0';
            if(campoAuxiliar[i][j]=='0'){
                campoAuxiliar[i][j]=' ';
            }
            soma = 0;
        }
    }
}
void imprimeCampoVizinha(char campoAuxiliar[N][M],int nlinha,int ncoluna){
    cout<<"\n"<<"Tabuleiro Vizinho:"<<endl;
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
    while (inicioLin < numLin) 
    {
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
                cout << "│" << campoAuxiliar[i][j];
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
    cout<<"\n"<<"Tabuleiro Final:"<<endl;
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