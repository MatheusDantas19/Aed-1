//Questão 17
#include <iostream>
#define  tam 3
using namespace std;
int MatDiagonalSec(int mat[tam][tam], int n);
int main(){
	int mat[tam][tam];
	int cont=0, i=0, j=0;
	cout<<"Digite os Valores da Matriz "<<"["<<tam<<"]"<<"["<<tam<<"]"<<endl;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			cin>>mat[i][j];
		}
	}
	cout<<"Soma da Diagonal Secundaria: "<<MatDiagonalSec(mat,tam)<<endl;
}


int MatDiagonalSec(int matriz[tam][tam], int n){
	int i,j,somaMatSec=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i+j==n-1){
				somaMatSec = somaMatSec+matriz[i][j];
			}
		}
	}
	return somaMatSec;
}