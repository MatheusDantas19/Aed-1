#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int Pali(char vet[],int ini,int fim);
int main(int argc, char const *argv[]){	
	char *palavra;
	palavra=(char*)malloc(sizeof(char));
	cin.getline(palavra,500);
	int tam=strlen(palavra);
	cout<<Pali(palavra,0,tam-1);
}
int Pali(char vet[],int ini,int fim){
	char l[50];
	if(ini>=fim)
		return 1;
	if(vet[ini]==vet[fim])
	 	Pali(vet,ini+1,fim-1);
	else return 0;	
}