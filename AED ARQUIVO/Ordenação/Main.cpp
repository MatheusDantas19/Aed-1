#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
void Quick(int vetor[], int inicio, int fim);
int main(int argc, char*argv[]){
	int id=0,cont=0,cont2=0,nVezes=0;
	char asteristico;
	string consulta,linha;
	ifstream arq1;
	// arq1.open("Consultas.txt",ios::in);
	ifstream arq("Consultas.txt");
	if(!arq.is_open()){
		cout<<"erro 404";
	 	return 1;
	}
	while(!arq.eof()){
		//getline(&line, &len , &arq);
		arq>>id;
		arq>>consulta;
		arq>>asteristico;
		arq>>nVezes;
		cont++;
	}
	int idVet[cont],idVet2[cont],nVezesVet[cont],nVezesVet2[cont],i=0,j=0;
	char asteristicoVet[cont];
	string consultaVet[cont],consultaVet2[cont];
	// arq1.close();
	arq1.open("Consultas.txt",ios::in);
	if(!arq1.is_open()){
		cout<<"erro 404";
	 	return 1;
	}
	cout<<"Arquivo Original: "<<endl;
	while(!arq1.eof() && j<cont){
		for (i = 0; i < cont; i++){
			arq1>>idVet[i];
			arq1>>consultaVet[i];
			arq1>>asteristicoVet[i];
			arq1>>nVezesVet[i];
			//ClonarValores
			idVet2[i]=idVet[i];
			consultaVet2[i]=consultaVet[i];
			nVezesVet2[i]=nVezesVet[i];
			cout<<idVet[i]<<" "<<consultaVet[i]<<" "<<asteristicoVet[i]<<nVezesVet[i];
			cout<<endl;
			j++;
		}
	}
	int acum=-99;
	Quick(nVezesVet,0,cont-1);
	cout<<"\n"<<"Arquivo Ordenado: "<<"\n";
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
	arq1.close();
	ofstream out;
	//Salvando em outro Arquivo
	out.open(argv[1],ios::out);
	if(!out.is_open()){
		cout<<"erro 404";
	 	return 1;
	}
	for(i=0;i<cont;i++){
		for(j=0;j<cont;j++){
			if(nVezesVet[i]==nVezesVet2[j]){
				if(nVezesVet[i]==acum){
					continue;
				}else{
					out<<idVet2[j]<<" "<<consultaVet2[j]<<" "<<asteristicoVet[i]<<nVezesVet2[j];
					out<<endl;
				}
			}
		}
		acum=nVezesVet[i];
	}
	out.close();
}

void Quick(int vetor[], int inicio, int fim){   
   int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;
   meio = ((i + j) / 2);
   pivo = vetor[meio];
   do{
      while (vetor[i] > pivo) i = i + 1;
      while (vetor[j] < pivo) j = j - 1;
      
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