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
	pessoa aux,*vet;
	int n,i;
	cout<<"Digite a qtd de pessoas: ";
	cin>>n;
	arqout.write((char*)&n,sizeof(int));
	vet=new pessoa[n];
	for (int i = 0; i < n; i++){
		cin.ignore();
		cout<<"Digite o nome: ";
		cin.getline(vet[i].nome,50);
		cout<<"Digite o endereco: ";
		cin.getline(vet[i].endereco,50);
		cout<<"Digite a idade: ";
		cin>>vet[i].idade;
		cout<<"Digite o salario: ";
		cin>>vet[i].salario;
		arqout.write((char*)vet,sizeof(pessoa)*n);
		cout<<"\n";
	}
	//cout<<"Tamanho da struct: ";
	//cout<<sizeof(pessoa)<<endl;
}