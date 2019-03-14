//Questão 16
#include <iostream>
#define  tam 3
using namespace std;
int MaiorValorMat(int mat[tam][tam], int n);
int main(){
	int mat[tam][tam];
	int cont=0, i=0, j=0;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			cin>>mat[i][j];
		}
	}
	cout<<"Maior: "<<MaiorValorMat(mat,tam);
}


int MaiorValorMat(int matriz[tam][tam], int n){
	int i=0,j=0,maiorValor=-9999;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(maiorValor<matriz[i][j]){
				maiorValor=matriz[i][j];
			}
		}
	}
	return maiorValor;
}