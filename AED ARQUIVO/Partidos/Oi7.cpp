//lendo gravando strings
#include <iostream>
#include <fstream>
#include <string.h>
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
	ifstream arqin("candinfo.dat",ios::binary);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	ifstream arqinCor("cor.idx",ios::binary);
	ifstream arqinPartido("partidos.idx",ios::binary);
	candidato aux;
	indice aux1,aux2;
	string linha;
	string nome="\0";
	int cont=0,pos=0,mulher=0;
	if(!arqin.is_open()){
;		cout<<"*";
		return 1;
	}
	if(!arqinCor.is_open()){
		cout<<"*";
		return 1;
	}
	if(!arqinPartido.is_open()){
		cout<<"*";
		return 1;
	}
	while(!arqin.eof()){
		arqin.read((char*)&aux,sizeof(candidato));
		arqinCor.read((char*)&aux1,sizeof(indice));
		arqinPartido.read((char*)&aux2,sizeof(indice));
		if(aux1.valor[0]=='B'){
			if(aux2.valor[0]=='P'){
				if(aux2.valor[1]=='S'){
					if(aux2.valor[2]=='O'){
						if(aux2.valor[3]=='L'){
							cout<<aux.nome<<" "<<aux2.valor<<endl;
						}
					}
				}
			}
		}
		//cout<<aux1.valor<<endl;



	}
	cout<<cont<<endl;
	arqinCor.close();
	arqinPartido.close();
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