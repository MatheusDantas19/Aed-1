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
	ofstream arqout("aqrstruct.dat",ios::binary|ios::app);    //ofstream arqout("aqrstruct.dat",ios::binary|ios::app);
	pessoa aux;
	int n,i;
	cout<<"Digite a qtd de pessoas: ";
	cin>>n;
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
	//cout<<sizeof(pessoa)<<endl;
}