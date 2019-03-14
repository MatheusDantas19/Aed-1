#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void merge(int ini,int fim,int v[]);
void intercala(int p,int q,int r,int vet[]);
int main(int argc, char const *argv[]){	
	int vet[]={12,11,10,9,8,7,6,5,4,3,2,1};
	merge(0,12,vet);
	for(int i=0;i<12;i++){
		cout<<vet[i]<<" ";
	}
	cout<<endl;
}
void merge(int ini,int fim,int v[]){
    if(ini<fim-1){
        int meio=(ini+fim)/2;
        merge(ini,meio,v);
        merge(meio,fim,v);
        intercala(ini,meio,fim,v);
    }
}
void intercala(int p,int q,int r,int vet[]){
	int i,j,k,*w,tam=r-p;
	w=(int*)malloc(sizeof(int)*tam);
	i=p;
	j=q;
	k=0;
	while(i<q && j<r){
		if(vet[i]<=vet[j]) w[k++]=vet[i++];
		else w[k++]= vet[j++];
	}
	while(i<q) w[k++]=vet[i++];
	while(j<r) w[k++]=vet[j++];
	for (int i = p; i < r; i++){
		vet[i]=w[i-p];
	}
}