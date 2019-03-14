//lendo gravando strings
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct tdata{
 	short int dia, mes,ano;
}data;

typedef struct tcand{
 	unsigned int id;
 	char cargo[20];
 	char partido[20];
 	char nome[100];
 	char estado[3];
 	data nascimento;
 	char sexo[10];
 	char escolaridade[50];
 	char cor[10];
}candidato;

typedef struct tindice{
 char valor[20];
 int posicao;
}indice;
//ios::app gravar no final do arquivo

int main(){
	clock_t inicio, fim; 
	double tempoGasto=0;
	inicio=clock();
	ifstream arqinMulher("mulheres.idx",ios::binary);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	ifstream arqinAmazonas("amazonas.idx",ios::binary);
	ifstream arqinPartido("partidos.idx",ios::binary);
	candidato aux1;
	indice aux;
	int *vetorAmazonas;
	int *vetorMulheres;
 	int cont=0,mulher=0,amazonas=0,pos=0;
	vetorAmazonas=(int*)malloc(sizeof(int)*9560);
	vetorMulheres=(int*)malloc(sizeof(int)*158483);
	if(!arqinMulher.is_open()){
		cout<<"*";
		return 1;
	}
	if(!arqinAmazonas.is_open()){
		cout<<"*";
		return 1;
	}
	if(!arqinPartido.is_open()){
		cout<<"*";
		return 1;
	}
	while(!arqinAmazonas.eof()){
		arqinAmazonas.read((char*)&amazonas,sizeof(int));
		vetorAmazonas[cont]=amazonas/224;
		cont++;
	}
	//cout<<"Tam Amazonas: "<<cont<<endl;
	int tamA=cont;
	cont=0;
	while(!arqinMulher.eof()){
		arqinMulher.read((char*)&mulher,sizeof(int));
		vetorMulheres[cont]=mulher/224;
		cont++;
	}
	int tamM=cont;
	bool igual=false;
	//cout<<"Tam Mulher: "<<cont<<endl;
	cont=0;
	while(!arqinPartido.eof()){
		arqinPartido.read((char*)&aux,sizeof(indice));
		if(aux.valor[0]=='P'){
			if(aux.valor[1]=='M'){
				if(aux.valor[2]=='D'){
					if(aux.valor[3]=='B'){
						int tamPartido=arqinPartido.tellg()/24;
						pos=aux.posicao/224;
						if(tamPartido<=9581 ){
							tamPartido=0;
						}
						if(tamPartido!=0){
							for(int i=0;i<tamM;i++){
								if(vetorMulheres[i]==pos){
									igual=true;
									break;
								}
								if(pos<vetorMulheres[i]){
									break;
								}
							}
						}
						if(igual==true){
							for(int i=0;i<tamA;i++){
								if(pos==vetorAmazonas[i]){
									cont++;
									break;
								}
								if(pos<vetorAmazonas[i]){
									break;
								}				
							}
						}

					}
				}
			}
		}
		igual=false;
	}
	cout<<"QTD MULHERES: "<<cont<<endl;
	fim=clock();
	tempoGasto=(fim-inicio)/(CLOCKS_PER_SEC/1000);
	cout<<"Tempo: "<<tempoGasto<<endl;
	arqinPartido.close();
	arqinAmazonas.close();
	arqinMulher.close();
}