//Questão 15
#include <iostream>
#define  tam 3
using namespace std;
int Mat(int mat[tam][tam], int n, int numero);
int main(){
	int mat[tam][tam];
	int cont=0, i=0, j=0, num=0;
	cout<<"Digite um numero inteiro: ";
	cin>>num;
	cout<<"Digite os valores da matriz: "<<tam<<"x"<<tam<<endl;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			cin>>mat[i][j];
		}
	}
	cout<<"Retorno: "<<Mat(mat,tam,num);
}

int Mat(int matriz[tam][tam], int n, int numero){
	int i=0,j=0,res=0,cont=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriz[i][j]==numero){
				cont++;
			}else{
				cont=0;
			}
			if(cont==4){
				res=1;
				break;
			}
		}
	}
	return res;
}