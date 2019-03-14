#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
//ios::app gravar no final do arquivo

int main(int argc,char *argv[]){
    ifstream arqin(argv[1],ios::binary);
    int n,e1,e2,s1,s2,flag;
    arqin.read((char*)&n,sizeof(int));
    arqin.read((char*)&e1,sizeof(int));
    arqin.read((char*)&e2,sizeof(int));
    arqin.read((char*)&s1,sizeof(int));
    arqin.read((char*)&s2,sizeof(int));
    int **m;
    m=(int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++){
        m[i]=(int*)malloc(sizeof(int)*n);      
    }    
    int mat[n][n];
    for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            arqin.read((char*)&flag,sizeof(int));   
            mat[i][j]=flag;       
        }   
    }

}


