#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(){
	int chances=0,cont=0,acum=0;
	bool ganhou=false,achou=false,chance=false,palavraRepetida=false;
	char *palavra,palavraDaVez,*dica;
	palavra=(char*)malloc(sizeof(char));
	dica=(char*)malloc(sizeof(char));
	cout<<"Digite a palavra secreta: ";
	cin.getline(palavra,255);
	system("clear");
	cout<<"Digite uma Dica: ";
	cin.getline(dica,255);
	int tam2=strlen(dica);
	dica[tam2]='\0';
	system("clear");
	int tam=strlen(palavra);
	char* palavraSecreta=(char*)malloc(sizeof(char)*tam);
	for(int i=0;i<tam;i++){
		if(palavra[i]==' '){
			palavraSecreta[i]=' ';
		}else{
			palavraSecreta[i]='_';		
		}
	}
	cout<<"Digite as quantidades de chances: ";
	cin>>chances;
	acum=chances;
	if(chances==6){
		chance=true;
	}else{
		chance=false;
	}
	cout<<"Dica: "<<dica<<endl;
	cout<<endl;
	for(int i=0;i<tam;i++){
		cout<<palavraSecreta[i];
	}
	cout<<endl;
	while(chances!=0 && !ganhou){
		//for(int i=0;i<tam;i++)
		//	cout<<palavraSecreta[i];
		//}
		cout<<"Digite uma letra: "<<endl;
		cin>>palavraDaVez;
		for(int i=0;i<tam;i++){
			if(palavraSecreta[i]==palavraDaVez||toupper(palavraSecreta[i])==toupper(palavraDaVez)){
				palavraRepetida=true;
				break;
			}
		}
		cout<<"Dica: "<<dica<<endl;
		system("clear");
		cout<<"Dica: "<<dica<<endl;
		//system("clear");
		//cout<<"Dica: "<<dica<<endl;
		if(palavraRepetida==false){
			for(int i=0;i<tam;i++){
				if(palavra[i]==palavraDaVez||toupper(palavra[i])==toupper(palavraDaVez)){
					palavraSecreta[i]=palavra[i];
					achou=true;

				}
			}
		}else{
			cout<<"VOCÊ JÁ DIGITOU ESSA PALAVRA!!!"<<endl;
		}
		//system("clear");
		if(achou==false &&palavraRepetida==false){
			chances--;
		}
		cout<<"Situação: "<<endl;
		if(chances==6 && chance==true){
			cout<<"______"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
		}
		if(chances==5 && chance==true){
			cout<<"______"<<endl;
			cout<<"|    0"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
		}
		if(chances==4 && chance==true){
			cout<<"______"<<endl;
			cout<<"|    0"<<endl;
			cout<<"|   /"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
		}
		if(chances==3 && chance==true){
			cout<<"______"<<endl;
			cout<<"|    0"<<endl;
			cout<<"|   /|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
		}
		if(chances==2 && chance==true){
			cout<<"______"<<endl;
			cout<<"|    0"<<endl;
			cout<<"|   /|\\"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
		}
		if(chances==1 && chance==true){
			cout<<"______"<<endl;
			cout<<"|    0"<<endl;
			cout<<"|   /|\\"<<endl;
			cout<<"|   /"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
		}
		if(chances==0 && chance==true){
			cout<<"______"<<endl;
			cout<<"|    0"<<endl;
			cout<<"|   /|\\"<<endl;
			cout<<"|   / \\"<<endl;
			cout<<"|"<<endl;
		}

		cout<<"\n";
		for(int i=0;i<tam;i++){
			cout<<palavraSecreta[i];
		}
		cout<<"\nchances restantes:"<<chances<<endl;
		for(int i=0;i<tam;i++){
			if(palavraSecreta[i]==palavra[i]){
				cont++;
			}
		}
		if(cont==tam){
			ganhou=true;
		}
		cont=0;	
		achou=false;
		palavraRepetida=false;
	}
	if(ganhou==true){
		cout<<"\n\n";
		cout<<"PARABÉNS VOCÊ GANHOU !!!!!!!!!!!!!!!"<<endl;
		cout<<"Palavra Secreta: "<<palavra<<endl;
	}else{
		cout<<"\n\n";
		cout<<"VOCÊ PERDEU !!!!!!!!!!!!!!"<<endl;
		cout<<"Palavra Secreta era: *"<<palavra<<"*"<<endl;
	}

}