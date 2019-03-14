//lendo gravando strings
#include <iostream>
#include <fstream>
using namespace std;
typedef struct agenda{
	int idade;
	char nome[50];
	char endereco[120];
	double salario;
}pessoa;
//ios::app gravar no final do arquivo

int main(){
	ifstream arqin("aqrstruct.dat",ios::binary);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	pessoa aux;
	int n;
	cout<<"Posicao arquivo: "<<arqin.tellg()<<endl;
	arqin.read((char*)&aux,sizeof(pessoa));
	while(!arqin.eof()){
		cout<<aux.nome<<endl;
		cout<<aux.endereco<<endl;
		cout<<aux.idade<<endl;
		cout<<aux.salario<<endl;
		cout<<"Posicao arquivo: "<<arqin.tellg()<<endl;
		arqin.read((char*)&aux,sizeof(pessoa));
	}
	cout<<"Posicao arquivo: "<<arqin.tellg()<<endl;

}

//teelp(retorna a posicao atual de escrita ou lendo);