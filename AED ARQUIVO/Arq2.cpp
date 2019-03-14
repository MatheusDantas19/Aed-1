#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int *tamN;
//void intercala(int p,int q,int r,no* vet);
//void merge(int ini,int fim, no* v);    
typedef struct no{
    char* id;
}no;
typedef struct tdata{
 	char *dia,*mes,*ano;
}data;
typedef struct tdata2{
    char *dia2,*mes2,*ano2;
}data2;
typedef struct Dados1{
	char *nome2;
	char *num2;
	data2 nascimento2;
}dados2;
typedef struct Dados{
	char *nome;
	char *num;
	data nascimento;
}dados;
void intercala(int p,int q,int r,no* vet){
    int i,j,k,tam=r-p;
    // char* w;
    no* w = (no*) malloc (sizeof(no)**tamN);
    for(int i = 0; i < *tamN; i++){
        w[i].id = (char*) malloc(sizeof(char)*6);
    }
	// w = (char*) malloc(sizeof(char)*4);
	i=p;
	j=q;
	k=0;
	while(i<q && j<r){
        if(strcmp(vet[i].id, vet[j].id) < 0 || strcmp(vet[i].id, vet[j].id) == 0)
            w[k++]=vet[i++];
		else w[k++]= vet[j++];
	}
	while(i<q) w[k++]=vet[i++];
	while(j<r) w[k++]=vet[j++];
	for (int i = p; i < r; i++){
		vet[i]=w[i-p];
    }
}

void merge(int ini,int fim, no* v){
    if(ini<fim-1){
        int meio=(ini+fim)/2;
        merge(ini,meio,v);
        merge(meio,fim,v);
        intercala(ini,meio,fim,v);
    }
}
int main(int argc, char*argv[]){
	int n=0;
	ifstream arq(argv[1]);
	if(!arq.is_open()){
		cout<<"erro 404";
	 	return 1;
    }
    arq>>n;
   // data2 *ndata2=new data2[n];
    tamN=&n;
    dados *ndados= new dados[n];
    dados2 *ndados2 = new dados2[n];
    string d,m,a;
    arq.seekg(2,ios::beg);
    short int dia,mes,ano;
    char *num=new char[9],*nome=new char[50],*data=new char[10];
	for(int i=0;i<n;i++){
        ndados[i].num=(char*)malloc(sizeof(char)*9);
        ndados[i].nome=(char*)malloc(sizeof(char));
        ndados2[i].num2=(char*)malloc(sizeof(char)*9);
        ndados2[i].nome2=(char*)malloc(sizeof(char));
        ndados[i].nascimento.dia=(char*)malloc(sizeof(char)*2);
        ndados[i].nascimento.mes=(char*)malloc(sizeof(char)*2);
        ndados[i].nascimento.ano=(char*)malloc(sizeof(char)*2);
        ndados2[i].nascimento2.dia2=(char*)malloc(sizeof(char)*2);
        ndados2[i].nascimento2.mes2=(char*)malloc(sizeof(char)*2);
        ndados2[i].nascimento2.ano2=(char*)malloc(sizeof(char)*2);
        arq.getline(ndados[i].nome,50);      
        arq.getline(ndados[i].num,9);
        ndados2[i].nome2=ndados[i].nome;
        ndados2[i].num2=ndados[i].num;
        arq.getline(data,10);
        for(int j=0;j<2;j++) d+=data[j];
        for(int j=3;j<5;j++) m+=data[j];
        for(int j=6;j<10;j++) a+=data[j];
        strcpy(ndados[i].nascimento.dia,d.c_str());
        strcpy(ndados[i].nascimento.mes,m.c_str());
        strcpy(ndados[i].nascimento.ano,a.c_str());;
        strcpy(ndados2[i].nascimento2.dia2,d.c_str());
        strcpy(ndados2[i].nascimento2.mes2,m.c_str());
        strcpy(ndados2[i].nascimento2.ano2,a.c_str());
        //cout<<ndados[i].nome<<endl;
        //cout<<ndados[i].num<<endl;
       // cout<<ndados[i].nascimento.dia<<"/"<<ndados[i].nascimento.mes<<"/"<<ndados[i].nascimento.ano<<endl;
        d="";
        m="";
        a="";
    }
   // arq.close();
    no* vetor = (no*) malloc(sizeof(no)*n);
    for(int i=0;i<n;i++){
        vetor[i].id=(char*)malloc(sizeof(char)*6);
    }
    //cout<<endl;
    for(int i=0;i<n;i++){
        vetor[i].id[0]=ndados[i].nascimento.ano[1];
        vetor[i].id[1]=ndados[i].nascimento.ano[0];
        vetor[i].id[2]=ndados[i].nascimento.mes[1];
        vetor[i].id[3]=ndados[i].nascimento.mes[0];
        vetor[i].id[4]=ndados[i].nascimento.dia[1];
        vetor[i].id[5]=ndados[i].nascimento.dia[0];
        //cout<<vetor[i].id<<endl;
        //break;
    }    
    merge(0,n,vetor);
    //cout<<endl;
   // char *aux=new char[6];
    int cont=0;
    for(int i=0;i<n;i++){
        char *aux=new char[6];
        int tam=strlen(vetor[i].id);
        if(i>=0 && i<n){
            for(int j=tam;j>=0;j--){
                aux[cont]=vetor[i].id[j-1];
                cont++;
            }
            vetor[i].id=aux;
        }
        ndados[i].nascimento.dia[0]=vetor[i].id[0];
        ndados[i].nascimento.dia[1]=vetor[i].id[1];
        ndados[i].nascimento.mes[0]=vetor[i].id[2];
        ndados[i].nascimento.mes[1]=vetor[i].id[3];
        ndados[i].nascimento.ano[0]=vetor[i].id[4];
        ndados[i].nascimento.ano[1]=vetor[i].id[5];
        //aux='\0';
        cont=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(strcmp(ndados[i].nascimento.dia,ndados2[j].nascimento2.dia2)==0){
                if(strcmp(ndados[i].nascimento.mes,ndados2[j].nascimento2.mes2)==0){
                    if(strcmp(ndados[i].nascimento.ano,ndados2[j].nascimento2.ano2)==0){
                        ndados[i].nome=ndados2[j].nome2;
                        ndados[i].num=ndados2[j].num2;
                    }
                    
                }
            }
           // cout<<ndados[i].nascimento.dia<<"=="<<ndados2[j].nascimento2.dia2<<endl;
        }
        //break;
    }
    //cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<ndados[i].nome<<endl;
        cout<<ndados[i].num<<endl;
        cout<<ndados[i].nascimento.dia<<"/"<<ndados[i].nascimento.mes<<"/"<<ndados[i].nascimento.ano<<endl;
    }
    //cout<<endl<<aux<<endl;
    arq.close();
}
