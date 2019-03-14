//Alunos: Matheus Inacio e Felipe Costa
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <iostream>
using namespace std;
#define tam 4
char verifica(char mapa[],int tamanho,int posicao)
{
	int indice=posicao/8;
	char mask=1;
	return mask&(mapa[indice]>>(posicao-8*indice));
}
void verdadeiro(char mapa[],int tamanho,int posicao)
{	
	int indice=posicao/8;
	char mask=1;
	mapa[indice]= mapa[indice]|(mask<<(posicao-8*indice));
	cout<<bitset<8>(mapa[indice])<<endl;
}
void falso(char mapa[],int tamanho,int posicao)
{
	int indice=posicao/8;
	char mask=1;
	mapa[indice] = mapa[indice] & (~(mask<<(posicao-8*indice)));
	cout<<bitset<8>(mapa[indice])<<endl;
}
char inverte(char mapa[],int tamanho,int posicao)
{
	int indice=posicao/8;
	char mask=1;
	mapa[indice]= mapa[indice]^(mask<<(posicao-8*indice));
	return mask^(mapa[indice]>>(posicao-8*indice));
}
char *criaMapa(int tamanho){
	char *enderMap;
	int temp=0;
	
	temp=(tamanho%8)?tamanho+(8-(tam%8)):tam;
	enderMap=(char*)malloc(temp);
	return enderMap;
}
char* aumentaMapa(char* mapa, int tamanhoOriginal, int tamanhoNovo){
	char *enderNMap;
	int tamNMap=0,cont=0;
	
	tamNMap=(tamanhoNovo%8)?tamanhoNovo+(8-(tam%8)):tamNMap;
	enderNMap=(char*)malloc(tamNMap);
	tamNMap=tamanhoOriginal;
	if(tamanhoOriginal%8){
		tamNMap=tamanhoOriginal+(8-(tamanhoOriginal%8));
	}
	
	
	for(cont;cont<tamanhoOriginal;cont++)
	{
		*(enderNMap+cont) = *(mapa+cont);
	}
	*(enderNMap+cont)=0;
	free(mapa);
	
	return enderNMap;
}
void destroiMapa(char *mapa){
	free(mapa);
}
void juntaMapa(char* mapa, int tamanho,char* novoMapa, int novoTamanho){
	char *novoMapa1;
	int cont=0;
	novoMapa1=criaMapa(tamanho+novoTamanho);
	for(cont=0;cont<tamanho;cont++){
		*(novoMapa1+cont) = *(mapa+cont);
	} 
	for(int cont2=0;cont2<novoTamanho;cont2++){
		*(novoMapa1+cont) = *(mapa+cont2);
		cont=cont+1;
	} 
	*(novoMapa1+cont)=0;
}
int main(){

}