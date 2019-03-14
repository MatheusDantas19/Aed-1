#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct Dad{
    char datax[8];
}paux;
typedef struct Data{
    char dia[2];
    char mes[2];
    char ano[2];
}Tdata;
typedef struct Dados{
    char num[9];
    char *nome;
    Tdata nascimento;
}Tdados;
int *tamN;
/*void intercala(int p,int q,int r,Tdados* vet){
    int i,j,k,tam=r-p;
    Tdados* w = (Tdados*) malloc (sizeof(Tdados)**tamN);
	i=p;
	j=q;
	k=0;
	while(i<q && j<r){
        if((vet[i].data < vet[j].data) || (vet[i].data== vet[j].data))
            w[k++]=vet[i++];
		else w[k++]= vet[j++];
	}
	while(i<q) w[k++]=vet[i++];
	while(j<r) w[k++]=vet[j++];
	for (int i = p; i < r; i++){
		vet[i]=w[i-p];
    }
}

void merge(int ini,int fim, Tdados* v){
    if(ini<fim-1){
        int meio=(ini+fim)/2;
        merge(ini,meio,v);
        merge(meio,fim,v);
        intercala(ini,meio,fim,v);
    }
}*/
int main(int argc,char *argv[]){
    ifstream arq(argv[1]);
    if(!arq.is_open()) return 1;
    int n;
    char *aux = new char[8];
    arq>>n;
    arq.seekg(2,ios::beg);
    Tdata *data = new Tdata[n];
    Tdados *dados = new Tdados[n];
    paux *datas = new paux[n];
    for(int i=0;i<n;i++){
        dados[i].nome=(char*)malloc(sizeof(char));
        arq>>dados[i].nome;
        arq>>dados[i].num;
        arq>>datas[i].datax;
        cout<<dados[i].nome<<endl;
        cout<<dados[i].num<<endl;
        cout<<datas[i].datax<<endl;
        cout<<endl;
    }

  
}