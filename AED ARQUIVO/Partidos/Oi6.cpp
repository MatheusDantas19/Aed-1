//lendo gravando strings
#include <iostream>
#include <fstream>
#include <string.h>
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
//ios::app gravar no final do arquivo

int main(){
	time_t inicio,fim;
	clock_t tempoInicial, tempoFinal; 
	double tempoGasto=0;
	ifstream arqin("candinfo.dat",ios::binary);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	ifstream arqinMulher("mulheres.idx",ios::binary);
	candidato aux;
	string linha;
	string nome="\0";
	int cont=0,pos=0,mulher=0;
	if(!arqin.is_open()){
		return 1;
	}
	if(!arqinMulher.is_open()){
		return 1;
	}
	tempoInicial = clock();
	while(!arqinMulher.eof()){
		arqinMulher.read((char*)&mulher,sizeof(int));
		arqin.seekg(mulher,ios::beg);
		//arqin.read((char*)&aux,sizeof(candidato));
		if(aux.escolaridade[0]=='S'){
			if(aux.escolaridade[9]=='C'){
				cont++;
			}
		}
		//arqin.seekg(pos*sizeof(candidato),ios::beg);
		//arqin.read((char*)&aux,sizeof(candidato));
		/*if(aux.sexo[0]=='F'){
			if(aux.escolaridade[0]=='S'){
				if(aux.escolaridade[9]=='C'){
					cont++;
				}
			}
		}*/
	}
	cout<<cont<<endl;
	tempoFinal = clock();
	tempoGasto = (tempoFinal-tempoInicial)/(CLOCKS_PER_SEC/1000);
	cout<<"Tempo Gasto em Milisegundos: "<<tempoGasto<<endl;
	arqinMulher.close();
	arqin.close();
	arqin.open("candinfo.dat",ios::binary);
	cont=0;
	if(!arqin.is_open()){
		return 1;
	}
	//while(!arqin.eof()){
	//	cont++;
	//	arqin.read((char*)&aux,sizeof(candidato));
	//}
	tempoInicial = clock();
	while(!arqin.eof()){
		arqin.read((char*)&aux,sizeof(candidato));
		if(aux.sexo[0]=='F'){
			if(aux.escolaridade[0]=='S'){
				if(aux.escolaridade[9]=='C'){
					cont++;
				}
			}
		}	
	} 
	tempoFinal = clock();
	tempoGasto = (tempoFinal-tempoInicial)/(CLOCKS_PER_SEC/1000);
	cout<<cont<<endl;
	cout<<"Tempo Gasto em Milisegundos da versão antiga é: "<<tempoGasto<<endl;
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