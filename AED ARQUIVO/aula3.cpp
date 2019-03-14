#include <iostream>
#include <fstream>
using namespace std;
typedef struct agenda{
	int idade;
	char nome[50];
	char endereco[120];
	double salario;
}pessoa;
int main(){
	fstream arq;
	arq.open(argv[1]);
	arq.seekg(0,ios::end);
	arq.close();
}