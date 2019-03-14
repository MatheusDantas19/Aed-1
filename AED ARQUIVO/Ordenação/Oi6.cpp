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
//ios::app gravar no final do arquivo

int main(){
	ifstream arqin("mulheres.idx",ios::binary);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	candidato aux;
	string linha;
	string nome="\0";
	int cont=0;
	if(!arqin.is_open()){
		return 1;
	}
	while(!arqin.eof()){
		cont++;
		arqin.read((char*)&aux,sizeof(candidato));
	}
	//arqin.seekg(1344,ios::beg);
	//arqin.read((char*)&aux,sizeof(candidato));
	//cout<<aux.nome<<endl;
	//arqin.seekg(-224,ios::end);
	//arqin.read((char*)&aux,sizeof(candidato));
	//cout<<aux.nome<<endl;
	cout<<cont<<endl;
	//cout<<arqin.tellg()<<endl;
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