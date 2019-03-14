//lendo gravando strings
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
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
	ifstream arqin("candinfo.dat",ios::binary);
	ifstream arqinMulher("mulheres.idx",ios::binary);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	ifstream arqinAmazonas("amazonas.idx",ios::binary);
	ifstream arqinPartido("partidos.idx",ios::binary);
	candidato aux1;
	indice aux;
	int *a,i,j;
	int *m;
 	int cont=0,mulher=0,amazonas=0,pos=0;
	a=(int*)malloc(sizeof(int)*9560);
	m=(int*)malloc(sizeof(int)*158483);
	if(!arqin.is_open()){
		cout<<"*";
		return 1;
	}
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
		//arqin.read((char*)&aux1,sizeof(candidato));
		//arqinMulher.read((char*)&mulher,sizeof(int));
		arqinAmazonas.read((char*)&amazonas,sizeof(int));
		//arqinPartido.read((char*)&aux,sizeof(indice));
		//pos=mulher/224;
		a[cont]=amazonas/224;
		//cout<<a[cont]<<endl;
		cont++;
		//cout<<pos<<endl;
	}
	cout<<"Amazonas: "<<cont<<endl;
	int tamA=cont;
	cont=0;
	while(!arqinMulher.eof()){
		arqinMulher.read((char*)&mulher,sizeof(int));
		m[cont]=mulher/224;
		cont++;
	}
	int tamM=cont;
	bool mulherD=false;
	cout<<"Mulher: "<<cont<<endl;
	cont=0;
	while(!arqinPartido.eof()){
		arqinPartido.read((char*)&aux,sizeof(indice));
		if(aux.valor[0]=='P'){
			if(aux.valor[1]=='M'){
				if(aux.valor[2]=='D'){
					if(aux.valor[3]=='B'){
						int par=arqinPartido.tellg()/24;
						pos=aux.posicao/224;
						if(par<=9581){
							par=0;
						}
						if(par!=0){
							for(int i=0;i<tamM;i++){
								if(m[i]==pos){
									mulherD=true;
									break;
								}
								if(pos<m[i]){
									break;
								}
							}
						}
						if(mulherD==true){
							for(int i=0;i<tamA;i++){
								//cout<<a[i]<<endl;
								if(pos==a[i]){
									cont++;
									break;
								}
								if(pos<a[i]){
									break;
								}				
							}
						}

					}
				}
			}
		}
		//cout<<cont<<endl;
		mulherD=false;
		//cont++;
		//i++;
		//j++;
	}
	cout<<"QTD MULHERES: "<<cont<<endl;
	arqinPartido.close();
	arqinAmazonas.close();
	arqinMulher.close();
	arqin.close();
	/*arqin.open("candinfo.dat",ios::binary);
	cont=0;
	while(!arqin.eof()){
		arqin.read((char*)&aux1,sizeof(candidato));
		if(aux1.sexo[0]=='F'){
			if(aux1.partido[0]=='P'){
				if(aux1.partido[1]=='M'){
					if(aux1.partido[2]=='D'){
						if(aux1.partido[3]=='B'){
							if(aux1.estado[0]=='A'){
								if(aux1.estado[1]=='M'){
									cont++;
								}
							}

						}
					}
				}
			}
		}
	}
	cout<<cont<<endl;
	arqin.close();
	/*arqin.open("candinfo.dat",ios::binary);
	for(int i=0;i<100;i++){
		arqin.read((char*)&aux,sizeof(candidato));
	}
	cout<<arqin.tellg()<<endl;
	arqin.close();	
	for (int i = 0; i < n; i++){
		cin.ignore();
		cout<<"Digite o nome: ";
		cin.getline(aux.nome,50);
		cout<<"Digite o endereco: ";
		cin.getline(aux.endereco,50);
		cout<<"Digite a idade: ";
		cin>>aux.idade;
		cout<<"Digite o salario: ";
		cin>>aux.salario;
		arqout.write((char*)&aux,sizeof(pessoa));
		cout<<"\n";
	}
	//cout<<"Tamanho da struct: ";
	//cout<<sizeof(pessoa)<<endl;*/

}