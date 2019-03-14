//Questão 4
#include <iostream>
#include <stdio.h>
#include <string.h>
#define tam 150
using namespace std;
int Ufam(char vet[]);
int main(){
	char texto[tam];
	cout<<"Digite a frase: \n";
	cin.getline(texto,tam);
	cout<<"Retorno: "<<Ufam(texto)<<endl;
}
int Ufam(char vet[]){
	int ufam=0;
	for (int i = 0; i < tam; i++)
	{
		if (vet[i]=='U')
		{
			if (vet[i+1]=='F')
			{
				if (vet[i+2]=='A')
				{
					if (vet[i+3]=='M')
					{
						ufam=1;
					}
				}	
			}
		}
	}
	return ufam;
}