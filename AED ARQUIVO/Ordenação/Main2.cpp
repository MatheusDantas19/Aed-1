#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
void Quick(int vetor[], int inicio, int fim);
int main(int argc, char*argv[]){
	int id=0;
	int cont=0,cont2=0;
	char asteristico;
	string consulta;
	int nVezes=0;
	ifstream arq(argv[1]);
	if(!arq.is_open()){
		cout<<"erro 404";
		return 1;
	}
	while(!arq.eof()){
		arq>>id;
		arq>>consulta;
		arq>>asteristico;
		arq>>nVezes;
		cont++;
	}
	int idVet[cont],idVet2[cont];
	int nVezesVet[cont],nVezesVet2[cont];
	char asteristicoVet[cont];
	string consultaVet[cont],consultaVet2[cont];
	int j=0,i=0;
	//arq.seekg(0,ios::beg);
	arq.close();
	arq.open("Consultas.txt");
	//arq.seekg(0,ios::beg);
	cout<<"vetor"<<endl;
	while(!arq.eof() && j<cont){
		cout<<"\n";
		for (i = 0; i < cont; i++){
			arq>>idVet[i];
			idVet2[i]=idVet[i];
			arq>>consultaVet[i];
			consultaVet2[i]=consultaVet[i];
			arq>>asteristicoVet[i];
			arq>>nVezesVet[i];
			nVezesVet2[i]=nVezesVet[i];
			cout<<idVet[i]<<" "<<consultaVet[i]<<" "<<asteristicoVet[i]<<nVezesVet[i];
			cout<<endl;
			//arq>>id;
			//arq>>consulta;
			//arq>>asteristico;
			//arq>>nVezes;
			//cout<<id<<" "<<consulta<<" "<<asteristico<<nVezes;
			j++;
			
		}
	}
	int acum=-99;
	Quick(nVezesVet,0,cont-1);
	cout<<"\n"<<"ordenado"<<"\n";
	for(i=0;i<cont;i++){
		for(j=0;j<cont;j++){
			if(nVezesVet[i]==nVezesVet2[j]){
				if(nVezesVet[i]==acum){
					continue;
				}else{
					cout<<idVet2[j]<<" "<<consultaVet2[j]<<" "<<asteristicoVet[i]<<nVezesVet2[j];
					cout<<endl;
				}
			}
		}
		acum=nVezesVet[i];
	}
	cout<<endl;

	arq.close();
}

void Quick(int vetor[], int inicio, int fim){   
   int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;
   meio = ((i + j) / 2);
   pivo = vetor[meio];
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   
}