#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int qtd1=0,qtd2=0,qtd3=0,qtd4=0;
int pontoDupla1=0,pontoDupla2=0;
class Pilha{
	public:
		char *vet;
		int topo,tamanho,n;
		
		Pilha(int tam){
			vet = new char[tam];
			topo=0;	
			tamanho=tam;		
			n=0;
		}
		~Pilha(){
			delete [] vet;
		}
		int vazia(){
			if(topo==0) return 1;
			else return 0;
		}
		int cheia(){
			if(topo==tamanho) return 1;
			else return 0;
		}
		void push(char valor){
			//if(vazia()){
			 //	cout<<"Está vazia"<<endl; 
			 //	return 1;
			//}else
			if(!cheia()) vet[topo++]=valor;
			else cout<<"cheia"<<endl;
			n++;
		}
		char top(){
			if(vazia()){
				cout<<"Está vazia"<<endl; 
			 	return 1;
			 }else{
			 	return vet[topo-1];
			 }
		}
		char top2(){
			if(vazia()){
				cout<<"Está vazia"<<endl; 
			 	return 1;
			 }else{
			 	return vet[topo-2];
			 }
		}
		char pop(){
			if(vazia()){
				cout<<"Está vazia"<<endl; 
			 	return 1;
			 }else{
			 	return vet[--topo];
			 }
			 n--;
		}
		void limpa(){
			while(!vazia()){
				cout<<pop()<<endl;
			}
			//topo=0;
		}
		int tam(){
			return n;
		}
		void imprime(){
			int cont=1,cont2=2;
			while(cont<n){
				//if(cont==n)
				cout<<vet[cont]<<"|";
				cout<<vet[cont2]<<" ";
				cont+=2;
				cont2+=2;
			}
		}
};
typedef struct Tdomino{
	char fichas[2];
}pecas;
void preenche(pecas *p, int vetA[], int vetB[]);
void embaralhar(int vet[], int tam);
void preenche(pecas *p, int vetA[], int vetB[]);
void imprimeMao(pecas *P1,pecas *P2,pecas *P3,pecas *P4);
void P1(pecas *p,pecas *p1);
void P2(pecas *p,pecas *p2);
void P3(pecas *p,pecas *p3);
void P4(pecas *p,pecas *p4);
void maoP1(pecas *p1);
void maoP2(pecas *p2);
void maoP3(pecas *p3);
void maoP4(pecas *p4);
void Tabuleiro(pecas *p1,pecas *p2,pecas *p3,pecas *p4);

int main(){
	pecas *p= new pecas[28];
	pecas *p1=new pecas[7],*p2=new pecas[7],*p3=new pecas[7],*p4=new pecas[7];
	int i=0,j=0,cont=0,vetA[28],vetB[28],k=0;
	while(i<=6){
		j=0;
		while(j<=i){
			vetA[k]=j;
			vetB[k]=i;
			j++;
			k++;
		}
		i++;
	}
	embaralhar(vetA,28);
	embaralhar(vetB,28);
	preenche(p,vetA,vetB);
	P1(p,p1);
	P2(p,p2);
	P3(p,p3);
	P4(p,p4);
	imprimeMao(p1,p2,p3,p4);
	Tabuleiro(p1,p2,p3,p4);
	delete p,p1,p2,p3,p4;
}
void preenche(pecas *p, int vetA[], int vetB[]){
	for(int i=0;i<28;i++){
		if(vetA[i]==0){
			p[i].fichas[0]=' ';
		}else{
			p[i].fichas[0]=vetA[i]+'0';
		}
	}
	for(int i=0;i<28;i++){
		if(vetB[i]==0){
			p[i].fichas[1]=' ';
		}else{
			p[i].fichas[1]=vetB[i]+'0';
		}
	}
}
void embaralhar(int vet[], int tam){
	srand(time(NULL));
	for (int i = 0; i < tam; i++){
		int r = rand() % tam;
		int temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}
void P1(pecas *p,pecas *p1){
	for(int i=0;i<7;i++){
		p1[i].fichas[0]=p[i].fichas[0];
		p1[i].fichas[1]=p[i].fichas[1];
	}
}
void P2(pecas *p,pecas *p2){
	int cont=0;
	for(int i=7;i<7*2;i++){
		p2[cont].fichas[0]=p[i].fichas[0];
		p2[cont].fichas[1]=p[i].fichas[1];
		cont++;
	}
}
void P3(pecas *p,pecas *p3){
	int cont=0;
	for(int i=14;i<7*3;i++){
		p3[cont].fichas[0]=p[i].fichas[0];
		p3[cont].fichas[1]=p[i].fichas[1];
		cont++;
	}
}
void P4(pecas *p,pecas *p4){
	int cont=0;
	for(int i=21;i<28;i++){
		p4[cont].fichas[0]=p[i].fichas[0];
		p4[cont].fichas[1]=p[i].fichas[1];
		cont++;
	}
}
void imprimeMao(pecas *p1,pecas *p2,pecas *p3,pecas *p4){
	char letra[]="abcdefg";
	cout<<"\nJogador 1: "<<endl;
	for(int i=0;i<7;i++){
		cout<<p1[i].fichas[0]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<p1[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
	//
	cout<<"\nJogador 2: "<<endl;
	for(int i=0;i<7;i++){
		cout<<p2[i].fichas[0]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<p2[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
	////
	cout<<"\nJogador 3: "<<endl;
	for(int i=0;i<7;i++){
		cout<<p3[i].fichas[0]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<p3[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
	////
	cout<<"\nJogador 4: "<<endl;
	for(int i=0;i<7;i++){
		cout<<p4[i].fichas[0]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 7; i++){
		cout<<p4[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl<<endl;
}
void maoP1(pecas *p1){
	int cont=0;
	char letra[]="abcdefg";
	cout<<"\nJogador 1: "<<endl;
	for(int i=0;p1[i].fichas[0]!='\0';i++){
		cout<<p1[i].fichas[0]<<" ";
		cont++;
	}
	cout<<endl;
	for (int i = 0; i < cont; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; p1[i].fichas[1]!='\0'; i++){
		cout<<p1[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<cont;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
}
void maoP2(pecas *p2){
	int cont=0;
	char letra[]="abcdefg";
	cout<<"\nJogador 2: "<<endl;
	for(int i=0;p2[i].fichas[0]!='\0';i++){
		cout<<p2[i].fichas[0]<<" ";
		cont++;
	}
	cout<<endl;
	for (int i = 0; i < cont; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; p2[i].fichas[1]!='\0'; i++){
		cout<<p2[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<cont;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
}
void maoP3(pecas *p3){
	int cont=0;
	char letra[]="abcdefg";
	cout<<"\nJogador 3: "<<endl;
	for(int i=0;p3[i].fichas[0]!='\0';i++){
		cout<<p3[i].fichas[0]<<" ";
		cont++;
	}
	cout<<endl;
	for (int i = 0; i < cont; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; p3[i].fichas[1]!='\0'; i++){
		cout<<p3[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<cont;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
}
void maoP4(pecas *p4){
	int cont=0;
	char letra[]="abcdefg";
	cout<<"\nJogador 4: "<<endl;
	for(int i=0;p4[i].fichas[0]!='\0';i++){
		cout<<p4[i].fichas[0]<<" ";
		cont++;
	}
	cout<<endl;
	for (int i = 0; i < cont; i++){
		cout<<"-"<<" ";
	}
	cout<<endl;
	for (int i = 0; p4[i].fichas[1]!='\0'; i++){
		cout<<p4[i].fichas[1]<<" ";
	}
	cout<<endl;
	for(int i=0;i<cont;i++){
		cout<<letra[i]<<" ";
	}
	cout<<endl;
}
void Tabuleiro(pecas *p1,pecas *p2,pecas *p3,pecas *p4){
	Pilha lado1(40),lado2(40),lado3(40),lado4(40),carroca(2);
	int pos,p=0;
	//bool seis=false;
	for(int i=0;i<7;i++){
		if(p1[i].fichas[0]=='6' && p1[i].fichas[1]=='6'){
			p=2;
			qtd1=1;
			carroca.push(p1[i].fichas[0]);
			carroca.push(p1[i].fichas[1]);
			for(int j=i;j<7;j++){
				if(j==6) {
					p1[j].fichas[0]='\0';
					p1[j].fichas[1]='\0';
					break;
				}
				if(j<=5){
   					p1[j].fichas[0] = p1[j+1].fichas[0];
   					p1[j].fichas[1] = p1[j+1].fichas[1];
				}
			}
		}
		if(p2[i].fichas[0]=='6' && p2[i].fichas[1]=='6'){
			p=3;
			qtd2=1;
			carroca.push(p2[i].fichas[0]);
			carroca.push(p2[i].fichas[1]);
			for(int j=i;j<7;j++){
				if(j==6) {
					p2[j].fichas[0]='\0';
					p2[j].fichas[1]='\0';
					break;
				}
				if(j<=5){
   					p2[j].fichas[0] = p2[j+1].fichas[0];
   					p2[j].fichas[1] = p2[j+1].fichas[1];
				}
			}
		}
		if(p3[i].fichas[0]=='6' && p3[i].fichas[1]=='6'){
			p=4;
			qtd3=1;
			carroca.push(p3[i].fichas[0]);
			carroca.push(p3[i].fichas[1]);
			for(int j=i;j<7;j++){
				if(j==6) {
					p3[j].fichas[0]='\0';
					p3[j].fichas[1]='\0';
					break;
				}
				if(j<=5){
   					p3[j].fichas[0] = p3[j+1].fichas[0];
   					p3[j].fichas[1] = p3[j+1].fichas[1];
				}
			}
		}
		if(p4[i].fichas[0]=='6' && p4[i].fichas[1]=='6'){
			p=1;
			qtd4=1;
			carroca.push(p4[i].fichas[0]);
			carroca.push(p4[i].fichas[1]);
			for(int j=i;j<7;j++){
				if(j==6) {
					p4[j].fichas[0]='\0';
					p4[j].fichas[1]='\0';
					break;
				}
				if(j<=5 ){
   					p4[j].fichas[0] = p4[j+1].fichas[0];
   					p4[j].fichas[1] = p4[j+1].fichas[1];
				}
			}
		}
	}
	if(p==1) {
		cout<<"Jogador "<<4<<" Comecou o jogo com a carroça:"<<endl;
		cout<<"Agora é a vez do Jogador 1 jogar: "<<endl;
	}
	else{
		cout<<"Jogador "<<p-1<<" Comecou o jogo com a carroça:"<<endl;
		cout<<"Agora é a vez do Jogador "<<p<<" jogar: "<<endl;
	}
	cout<<"Carroça: "<<carroca.top()<<"|"<<carroca.top()<<endl;
	lado1.push('6');
	lado2.push('6');
	lado3.push('6');
	lado4.push('6');
	cout<<"\nlado1:"<<" ";
	lado1.imprime();
	cout<<"\n\nlado2:"<<" ";
	lado2.imprime();
	cout<<"\n\nlado3:"<<" ";
	lado3.imprime();
	cout<<"\n\nlado4:"<<" ";
	lado4.imprime();

	cout<<endl;
	//imprimeMao(p1,p2,p3,p4);
	char c;
	int cont=0,n,lado,coordenada,contador=0;
	bool jodada=false,flag=false,jogou=false,passou=false;
	bool  errou=false,valida=false;
	int contPassou=0,pAux=0;
	while(cont<=200){
	//	if (cont>0) cout<<"\nAgora é a vez do Jogador "<<p<<" jogar:"<<endl;
		//imprimeMao(p1,p2,p3,p4);
		if(p==1 && !jogou){
			for(int i=0;i<7-qtd1;i++){
				if(p1[i].fichas[0]==lado1.top() || p1[i].fichas[1]==lado1.top()) contador++;
				if(p1[i].fichas[0]==lado2.top() || p1[i].fichas[1]==lado2.top()) contador++;
				if(p1[i].fichas[0]==lado3.top() || p1[i].fichas[1]==lado3.top()) contador++;
				if(p1[i].fichas[0]==lado4.top() || p1[i].fichas[1]==lado4.top()) contador++;
			}
			if(contador==0){
				contPassou++;
				cout<<"\nJogador "<<p<<"PASSOU!\n"<<endl;
				valida=true;
				jogou=true;
				p=2;
			}else{
				if(contPassou==3){
					pontoDupla2=pontoDupla2+50;
				}else if(contPassou==1){
					pontoDupla2=pontoDupla2+20;
				}else{
					contPassou=0;
				}
				int flagint=1;
				maoP1(p1);
				cout<<"Digite a letra da peça: ";
				while(flagint!=0){
					cin>>c;
					n=c-97;
					if(n>=0 && n<=6) break;
					n=0;
					c='\0';
					cout<<"Digite Novamente:"<<endl;
				}
				cout<<"Digite o lado a jogar: ";
				while(flagint!=0){
					cin>>lado;
					if(lado>=1 && lado<=4) break;
					cout<<"Digite Novamente:"<<endl;
				}
				while(flagint!=0){
					//cout<<"*";
					if(lado==1){
						if(p1[n].fichas[0]==lado1.top() || p1[n].fichas[1]==lado1.top())
							break;
					}else if(lado==2){
						if(p1[n].fichas[0]==lado2.top() || p1[n].fichas[1]==lado2.top())
							break;
					}else if(lado==3){
						if(p1[n].fichas[0]==lado3.top() || p1[n].fichas[1]==lado3.top())
						break;
					}else if(lado==4){
						if(p1[n].fichas[0]==lado4.top() || p1[n].fichas[1]==lado4.top())
						break;
					}
					cout<<"Jogada Imcompativel!!!"<<endl;
					cout<<"Digite novamente a letra da peça: "<<endl;
					cin>>c;
					n=c-97;
					cout<<"Digite novamente o lado: "<<endl;
					cin>>lado;
					
				}
				if(lado>=1 && lado<=4 && n>=0 && n<=6 && valida==false){
					jogou = true;
					if(lado==1){
						if(p1[n].fichas[0]==lado1.top()){
							lado1.push(p1[n].fichas[0]);
			 				lado1.push(p1[n].fichas[1]);
			 				qtd1++;
						}else if(p1[n].fichas[1]==lado1.top()){
							lado1.push(p1[n].fichas[1]);
							lado1.push(p1[n].fichas[0]);
							qtd1++;
						}else{
							cout<<"\nJogada Imcompativel!!! "<<endl;
							while(flagint!=0){
								cout<<"Digite novamente letra da peça: ";
								cin>>c;
								n=c-97;
								cout<<"Digite novamente o lado: ";
								cin>>lado;
								if(p1[n].fichas[0]==lado1.top()){
									lado1.push(p1[n].fichas[0]);
			 						lado1.push(p1[n].fichas[1]);
			 						break;
								}else if(p1[n].fichas[1]==lado1.top()){
									lado1.push(p1[n].fichas[1]);
									lado1.push(p1[n].fichas[0]);
									break;
								}
							}
							qtd1++;
							passou=true;
							//errou=true;
						}
					}else if(lado==2){
						if(p1[n].fichas[0]==lado2.top()){
							lado2.push(p1[n].fichas[0]);
			 				lado2.push(p1[n].fichas[1]);
			 				qtd1++;
						}else if(p1[n].fichas[1]==lado2.top()){
							lado2.push(p1[n].fichas[1]);
							lado2.push(p1[n].fichas[0]);
							qtd1++;
						}
					}else if(lado==3){
						if(p1[n].fichas[0]==lado3.top()){
							lado3.push(p1[n].fichas[0]);
				 			lado3.push(p1[n].fichas[1]);
				 			qtd1++;
						}else if(p1[n].fichas[1]==lado3.top()){
							lado3.push(p1[n].fichas[1]);
							lado3.push(p1[n].fichas[0]);
							qtd1++;
						}
					}else if(lado==4){
						if(p1[n].fichas[0]==lado4.top()){
							lado4.push(p1[n].fichas[0]);
				 			lado4.push(p1[n].fichas[1]);
				 			qtd1++;
						}else if(p1[n].fichas[1]==lado4.top()){
							lado4.push(p1[n].fichas[1]);
							lado4.push(p1[n].fichas[0]);
							qtd1++;
						}
					}
					for(int i=0;i<7 && passou==false;i++){
						if(i==7-qtd1) {
							p1[i].fichas[0]='\0';
							p1[i].fichas[1]='\0';
							break;
						}
						if(i==n){
							p1[i].fichas[0]=p1[i+1].fichas[0];
							p1[i].fichas[1]=p1[i+1].fichas[1];
							flag=true;
						}
						if(i<=7-qtd1-1 && flag==true){
		   					p1[i].fichas[0] = p1[i+1].fichas[0];
		   					p1[i].fichas[1] = p1[i+1].fichas[1];
						}
					}
					p=2;
				}			
			}
		}	
			
		passou=false;
		flag=false;
		if(p==2 && !jogou){
			for(int i=0;i<7-qtd1;i++){
				if(p2[i].fichas[0]==lado1.top() || p2[i].fichas[1]==lado1.top()) contador++;
				if(p2[i].fichas[0]==lado2.top() || p2[i].fichas[1]==lado2.top()) contador++;
				if(p2[i].fichas[0]==lado3.top() || p2[i].fichas[1]==lado3.top()) contador++;
				if(p2[i].fichas[0]==lado4.top() || p2[i].fichas[1]==lado4.top()) contador++;
			}
			if(contador==0){
				contPassou++;
				cout<<"Jogador "<<p<<"PASSOU!"<<endl;
				valida=true;
				jogou=true;
				p=3;
			}else{
				if(contPassou==3){
					pontoDupla2=pontoDupla2+50;
				}else if(contPassou==1){
					pontoDupla2=pontoDupla2+20;
				}else{
					contPassou=0;
				}
				int flagint=1;
				maoP2(p2);
				cout<<"Digite a letra da peça: ";
				while(flagint!=0){
					//cout<<"Digite Novamente:"<<endl;
					cin>>c;
					n=c-97;
					if(n>=0 && n<=6) break;
					n=0;
					c='\0';
					cout<<"Digite Novamente:"<<endl;
				}
				cout<<"Digite o lado a jogar: ";
				while(flagint!=0){
					//cout<<"Digite Novamente:"<<endl;
					cin>>lado;
					if(lado>=1 && lado<=4) break;
					cout<<"Digite Novamente:"<<endl;
				}
				while(flagint!=0){
					//cout<<"*";
					if(lado==1){
						if(p2[n].fichas[0]==lado1.top() || p2[n].fichas[1]==lado1.top())
							break;
					}else if(lado==2){
						if(p2[n].fichas[0]==lado2.top() || p2[n].fichas[1]==lado2.top())
							break;
					}else if(lado==3){
						if(p2[n].fichas[0]==lado3.top() || p2[n].fichas[1]==lado3.top())
						break;
					}else if(lado==4){
						if(p2[n].fichas[0]==lado4.top() || p2[n].fichas[1]==lado4.top())
						break;
					}
					cout<<"Jogada Imcompativel!!!"<<endl;
					cout<<"Digite novamente a letra da peça: "<<endl;
					cin>>c;
					n=c-97;
					cout<<"Digite novamente o lado: "<<endl;
					cin>>lado;
					
				}
				if(lado>=1 && lado<=4 && n>=0 && n<=6 && valida ==false){
					jogou = true;
					if(lado==1){
						if(p2[n].fichas[0]==lado1.top()){
							lado1.push(p2[n].fichas[0]);
				 			lado1.push(p2[n].fichas[1]);
				 			qtd2++;
						}else if(p2[n].fichas[1]==lado1.top()){
							lado1.push(p2[n].fichas[1]);
							lado1.push(p2[n].fichas[0]);
							qtd2++;
						}
					}else if(lado==2){
						if(p2[n].fichas[0]==lado2.top()){
							lado2.push(p2[n].fichas[0]);
				 			lado2.push(p2[n].fichas[1]);
				 			qtd2++;
						}else if(p2[n].fichas[1]==lado2.top()){
							lado2.push(p2[n].fichas[1]);
							lado2.push(p2[n].fichas[0]);
							qtd2++;
						}
					}else if(lado==3){
						if(p2[n].fichas[0]==lado3.top()){
							lado3.push(p2[n].fichas[0]);
				 			lado3.push(p2[n].fichas[1]);
				 			qtd2++;
						}else if(p2[n].fichas[1]==lado3.top()){
							lado3.push(p2[n].fichas[1]);
							lado3.push(p2[n].fichas[0]);
							qtd2++;
						}
					}else if(lado==4){
						if(p2[n].fichas[0]==lado4.top()){
							lado4.push(p2[n].fichas[0]);
				 			lado4.push(p2[n].fichas[1]);
				 			qtd2++;
						}else if(p2[n].fichas[1]==lado4.top()){
							lado4.push(p2[n].fichas[1]);
							lado4.push(p2[n].fichas[0]);
							qtd2++;
						}
					}
					for(int i=0;i<7 && passou==false;i++){
						if(i==7-qtd2) {
							p2[i].fichas[0]='\0';
							p2[i].fichas[1]='\0';
							break;
						}
						if(i==n){
							p2[i].fichas[0]=p2[i+1].fichas[0];
							p2[i].fichas[1]=p2[i+1].fichas[1];
							flag=true;
						}
						if(i<=7-qtd2-1 && flag==true){
		   					p2[i].fichas[0] = p2[i+1].fichas[0];
		   					p2[i].fichas[1] = p2[i+1].fichas[1];
						}
					}
					p=3;
				}
			}	
		}	
		passou=false;
		flag=false;
		if(p==3 && !jogou){
			for(int i=0;i<7-qtd1;i++){
				if(p3[i].fichas[0]==lado1.top() || p3[i].fichas[1]==lado1.top()) contador++;
				if(p3[i].fichas[0]==lado2.top() || p3[i].fichas[1]==lado2.top()) contador++;
				if(p3[i].fichas[0]==lado3.top() || p3[i].fichas[1]==lado3.top()) contador++;
				if(p3[i].fichas[0]==lado4.top() || p3[i].fichas[1]==lado4.top()) contador++;
				
			}
			if(contador==0){
				contPassou++;
				cout<<"Jogador "<<p<<"PASSOU!"<<endl;
				valida=true;
				jogou=true;
				p=4;
			}else{
				if(contPassou==3){
					pontoDupla1=pontoDupla1+50;
				}else if(contPassou==1){
					pontoDupla1=pontoDupla1+20;
				}else{
					contPassou=0;
				}
				int flagint=1;
				maoP3(p3);
				cout<<"Digite a letra da peça: ";
				while(flagint!=0){
					//cout<<"Digite Novamente:"<<endl;
					cin>>c;
					n=c-97;
					if(n>=0 && n<=6) break;
					n=0;
					c='\0';
					cout<<"Digite Novamente:"<<endl;
				}
				cout<<"Digite o lado a jogar: ";
				while(flagint!=0){
					//cout<<"Digite Novamente:"<<endl;
					cin>>lado;
					if(lado>=1 && lado<=4) break;
					cout<<"Digite Novamente:"<<endl;
				}
				while(flagint!=0){
					//cout<<"*";
					if(lado==1){
						if(p3[n].fichas[0]==lado1.top() || p3[n].fichas[1]==lado1.top())
							break;
					}else if(lado==2){
						if(p3[n].fichas[0]==lado2.top() || p3[n].fichas[1]==lado2.top())
							break;
					}else if(lado==3){
						if(p3[n].fichas[0]==lado3.top() || p3[n].fichas[1]==lado3.top())
						break;
					}else if(lado==4){
						if(p3[n].fichas[0]==lado4.top() || p3[n].fichas[1]==lado4.top())
						break;
					}
					cout<<"Jogada Imcompativel!!!"<<endl;
					cout<<"Digite novamente a letra da peça: "<<endl;
					cin>>c;
					n=c-97;
					cout<<"Digite novamente o lado: "<<endl;
					cin>>lado;
				}
				if(n>=0 &&  n<=7 && lado>=1 && lado<=4 && valida==false){
					jogou = true;
					if(lado==1){
						if(p3[n].fichas[0]==lado1.top()){
							lado1.push(p3[n].fichas[0]);
				 			lado1.push(p3[n].fichas[1]);
				 			qtd3++;
						}else if(p3[n].fichas[1]==lado1.top()){
							lado1.push(p3[n].fichas[1]);
							lado1.push(p3[n].fichas[0]);
							qtd3++;
						}
					}else if(lado==2){
						if(p3[n].fichas[0]==lado2.top()){
							lado2.push(p3[n].fichas[0]);
				 			lado2.push(p3[n].fichas[1]);
				 			qtd3++;
						}else if(p3[n].fichas[1]==lado2.top()){
							lado2.push(p3[n].fichas[1]);
							lado2.push(p3[n].fichas[0]);
							qtd3++;
						}
					}else if(lado==3){
						if(p3[n].fichas[0]==lado3.top()){
							lado3.push(p3[n].fichas[0]);
				 			lado3.push(p3[n].fichas[1]);
				 			qtd3++;
						}else if(p3[n].fichas[1]==lado3.top()){
							lado3.push(p3[n].fichas[1]);
							lado3.push(p3[n].fichas[0]);
							qtd3++;
						}
					}else if(lado==4){
						if(p3[n].fichas[0]==lado4.top()){
							lado4.push(p3[n].fichas[0]);
				 			lado4.push(p3[n].fichas[1]);
				 			qtd3++;
						}else if(p3[n].fichas[1]==lado4.top()){
							lado4.push(p3[n].fichas[1]);
							lado4.push(p3[n].fichas[0]);
							qtd3++;
						}
					}
					for(int i=0;i<7 && passou==false;i++){
						if(i==7-qtd3) {
							p3[i].fichas[0]='\0';
							p3[i].fichas[1]='\0';
							break;
						}
						if(i==n){
							p3[i].fichas[0]=p3[i+1].fichas[0];
							p3[i].fichas[1]=p3[i+1].fichas[1];
							flag=true;
						}
						if(i<=7-qtd3-1 && flag==true){
		   					p3[i].fichas[0] = p3[i+1].fichas[0];
		   					p3[i].fichas[1] = p3[i+1].fichas[1];
						}
					}
					p=4;
				}
			}
		}
		passou=false;
		if(p==4 && !jogou){
			for(int i=0;i<7-qtd1;i++){
				if(p4[i].fichas[0]==lado1.top() || p4[i].fichas[1]==lado1.top()) contador++;
				if(p4[i].fichas[0]==lado2.top() || p4[i].fichas[1]==lado2.top()) contador++;
				if(p4[i].fichas[0]==lado3.top() || p4[i].fichas[1]==lado3.top()) contador++;
				if(p4[i].fichas[0]==lado4.top() || p4[i].fichas[1]==lado4.top()) contador++;
				
			}
			if(contador==0){
				contPassou++;
				cout<<"Jogador "<<p<<"PASSOU!"<<endl;
				valida=true;
				jogou=true;
				p=1;
			}else{
				if(contPassou==3){
					pontoDupla2=pontoDupla2+50;
				}else if(contPassou==1){
					pontoDupla2=pontoDupla2+20;
				}else{
					contPassou=0;
				}
				int flagint=1;
				maoP4(p4);
				cout<<"Digite a letra da peça: ";
				while(flagint!=0){
					//cout<<"Digite Novamente:"<<endl;
					cin>>c;
					n=c-97;
					if(n>=0 && n<=6) break;
					n=0;
					c='\0';
					cout<<"Digite Novamente:"<<endl;
				}
				cout<<"Digite o lado a jogar: ";
				while(flagint!=0){
					//cout<<"Digite Novamente:"<<endl;
					cin>>lado;
					if(lado>=1 && lado<=4) break;
					cout<<"Digite Novamente:"<<endl;
				}
				while(flagint!=0){
					//cout<<"*";
					if(lado==1){
						if(p4[n].fichas[0]==lado1.top() || p4[n].fichas[1]==lado1.top())
							break;
					}else if(lado==2){
						if(p4[n].fichas[0]==lado2.top() || p4[n].fichas[1]==lado2.top())
							break;
					}else if(lado==3){
						if(p4[n].fichas[0]==lado3.top() || p4[n].fichas[1]==lado3.top())
						break;
					}else if(lado==4){
						if(p4[n].fichas[0]==lado4.top() || p4[n].fichas[1]==lado4.top())
						break;
					}
					cout<<"Jogada Imcompativel!!!"<<endl;
					cout<<"Digite novamente a letra da peça: "<<endl;
					cin>>c;
					n=c-97;
					cout<<"Digite novamente o lado: "<<endl;
					cin>>lado;
				}
				if(lado>=1 && lado<=4 && n>=0 && n<=6 && valida==false){	
					jogou=true;
					if(lado==1){
						if(p4[n].fichas[0]==lado1.top()){
							lado1.push(p4[n].fichas[0]);
				 			lado1.push(p4[n].fichas[1]);
				 			qtd4++;
						}else if(p4[n].fichas[1]==lado1.top()){
							lado1.push(p4[n].fichas[1]);
							lado1.push(p4[n].fichas[0]);
							qtd4++;
						}
					}else if(lado==2){
						if(p4[n].fichas[0]==lado2.top()){
							lado2.push(p4[n].fichas[0]);
				 			lado2.push(p4[n].fichas[1]);
				 			qtd4++;
						}else if(p4[n].fichas[1]==lado2.top()){
							lado2.push(p4[n].fichas[1]);
							lado2.push(p4[n].fichas[0]);
							qtd4++;
						}
					}else if(lado==3){
						if(p4[n].fichas[0]==lado3.top()){
							lado3.push(p4[n].fichas[0]);
				 			lado3.push(p4[n].fichas[1]);
				 			qtd4++;
						}else if(p4[n].fichas[1]==lado3.top()){
							lado3.push(p4[n].fichas[1]);
							lado3.push(p4[n].fichas[0]);
							qtd4++;
						}
					}else if(lado==4){
						if(p4[n].fichas[0]==lado4.top()){
							lado4.push(p4[n].fichas[0]);
				 			lado4.push(p4[n].fichas[1]);
				 			qtd4++;
						}else if(p4[n].fichas[1]==lado4.top()){
							lado4.push(p4[n].fichas[1]);
							lado4.push(p4[n].fichas[0]);
							qtd4++;
						}
					}
					for(int i=0;i<7 && passou==false;i++){
						if(i==7-qtd4) {
							p4[i].fichas[0]='\0';
							p4[i].fichas[1]='\0';
							break;
						}
						if(i==n){
							p4[i].fichas[0]=p4[i+1].fichas[0];
							p4[i].fichas[1]=p4[i+1].fichas[1];
							flag=true;
						}
						if(i<=7-qtd4-1 && flag==true){
		   					p4[i].fichas[0] = p4[i+1].fichas[0];
		   					p4[i].fichas[1] = p4[i+1].fichas[1];
						}
					}
					p=1;
				}
			}	
		}
		if(p==1) pAux=4;
		if(p>=2 && p<=4) pAux=p-1;
		int aux=0,aux2=0,aux3=0,jogada=0;
		if(lado1.tam()==1 || lado2.tam()==1 || lado3.tam()==1 || lado4.tam()==1 ){
			for(int i=0;i<1;i++){
				if(lado1.tam()==1){
					jogada++;
				}
				if(lado2.tam()==1){
					jogada++;
				}
				if(lado3.tam()==1){
					jogada++;
				}
				if(lado4.tam()==1){
					jogada++;
				}
			}
			if(jogada==3){
				aux3=12;
				if(lado1.tam()>1){
					if(lado1.top()==lado1.top2()){
						if(lado1.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
							aux3+=lado1.top2()-'0';		
						}
					}else{
						if(lado1.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
						}
									
					}
				}
				if(lado2.tam()>1){
					if(lado2.top()==lado2.top2()){
						if(lado2.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado2.top()-'0';
							aux3+=lado2.top2()-'0';
						}
					}else{
						if(lado2.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado2.top()-'0';
						}
					}
				}
				if(lado3.tam()>1){
					if(lado3.top()==lado3.top2()){
						if(lado3.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado3.top()-'0';
							aux3+=lado3.top2()-'0';
						}
					}else{
						if(lado3.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado3.top()-'0';
						}
					}
				}
				if(lado4.tam()>1){
					if(lado4.top()==lado4.top2()){
						if(lado4.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado4.top()-'0';
							aux3+=lado4.top2()-'0';
						}
					}else{
						if(lado4.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado4.top()-'0';
						}	
					}
				}
			}else if(jogada!=3){
				aux3=0;
				if(lado1.tam()==1){

				}else{
					if(lado1.top()==lado1.top2()){
						if(lado4.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
							aux3+=lado1.top2()-'0';
						}
					}else{
						if(lado1.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
						}	
					}
				}
				if(lado2.tam()==1){

				}else{
					if(lado1.top()==lado1.top2()){
						if(lado4.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
							aux3+=lado1.top2()-'0';
						}
					}else{
						if(lado1.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
						}	
					}
				}
				if(lado3.tam()==1){

				}else{
					if(lado1.top()==lado1.top2()){
						if(lado4.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
							aux3+=lado1.top2()-'0';
						}
					}else{
						if(lado1.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
						}	
					}
				}
				if(lado4.tam()==1){

				}else{
					if(lado1.top()==lado1.top2()){
						if(lado4.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
							aux3+=lado1.top2()-'0';
						}
					}else{
						if(lado1.top()==' '){
							aux3+=0;
						}else{
							aux3+=lado1.top()-'0';
						}	
					}
				}
			}
		}
		/if(pAux==1 && jogada!=3){
			if(lado==1){
				if(cont==0){
					if(lado1.top()==lado1.top2()){
						aux=lado1.top()-'0';
						aux+=lado1.top2()-'0';
						aux2=6+6;
					if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado1.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
						
					}
				}	
			}else if(lado==2){
				if(cont==0){
					if(lado2.top()==lado2.top2()){
						if(lado2.top()==' '){
							aux=aux+0;
						}else{
							aux=lado2.top()-'0';
							aux=lado2.top2()-'0';
							aux2=6+6;
						}
						
						if((aux2+aux && cont==0)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado2.top()-'0';
						aux2=6+6;
						if((aux2+aux && cont==0)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
				
			}else if(lado==3){
				if(cont==0){
					if(lado3.top()==lado3.top2()){
						aux=lado3.top()-'0';
						aux=lado3.top2()-'0';
						aux2=6+6;
						if((aux2+aux && cont==0)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado3.top()-'0';
						aux2=6+6;
						if((aux2+aux && cont==0)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
				
			}else if(lado==4){
				if(cont==0){
					if(lado4.top()==lado4.top2()){
						aux=lado4.top()-'0';
						aux=lado4.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado4.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
				
				
			}
		}else if(pAux==2 && jogada!=3){
			if(lado==1){
				if(cont==0){
					if(lado1.top()==lado1.top2()){
				 		aux=lado1.top()-'0';
						aux+=lado1.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado1.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}
				
			}else if(lado==2){
				if(cont==0){
					if(lado2.top()==lado2.top2()){
						aux=lado2.top()-'0';
						aux=lado2.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado2.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}
			}else if(lado==3){
				if(cont==0){
					if(lado3.top()==lado3.top2()){
						aux=lado3.top()-'0';
						aux=lado3.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado3.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}

				
			}else if(lado==4){
				if(cont==0){
					if(lado4.top()==lado4.top2()){
						aux=lado4.top()-'0';
						aux=lado4.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
				 		aux=lado4.top()-'0';
				 		aux2=6+6;
				 		if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}
			}

		}else if(pAux==3 && jogada!=3){
			if(lado==1){
				if(cont==0){
					if(lado1.top()==lado1.top2()){
						aux=lado1.top()-'0';
						aux+=lado1.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado1.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>0){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
				
				
			}else if(lado==2){
				if(cont==0){
					if(lado2.top()==lado2.top2()){
						aux=lado2.top()-'0';
						aux=lado2.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado2.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
				
			}else if(lado==3){
				if(cont==0){
					if(lado3.top()==lado3.top2()){
						aux=lado3.top()-'0';
						aux=lado3.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado3.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
			}else if(lado==4){
				if(cont==0){
					if(lado4.top()==lado4.top2()){		
						aux=lado4.top()-'0';
						aux=lado4.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}else{
						aux=lado4.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla1=pontoDupla1+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla1=pontoDupla1+aux;
					}
				}
				
			}

		}else if(pAux==4 && jogada!=3){
			if(lado==1){
				if(cont==0){
					if(lado1.top()==lado1.top2()){
						aux=lado1.top()-'0';
						aux+=lado1.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado1.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}	
				
			}else if(lado==2){
				if(cont==0){
					if(lado2.top()==lado2.top2()){
						aux=lado2.top()-'0';
						aux=lado2.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado2.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}

				
			}else if(lado==3){
				if(cont==0){
					if(lado3.top()==lado3.top2()){
						aux=lado3.top()-'0';
						aux=lado3.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado3.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}
			}else if(lado==4){
				if(cont==0){
					if(lado4.top()==lado4.top2()){
						aux=lado4.top()-'0';
						aux=lado4.top2()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}else{
						aux=lado4.top()-'0';
						aux2=6+6;
						if((aux2+aux)%5==0) pontoDupla2=pontoDupla2+aux2+aux;
					}
				}
				if(cont>1){
					if(lado1.tam()>1 && lado2.tam()>1 && lado3.tam()>1 && lado4.tam()>1){
						cout<<"**"<<endl;
						if(lado1.top()==lado1.top2()){
							if(lado1.top()==' '){
								aux=aux+0;
							}else{
								aux=aux+(lado1.top()-'0');
								aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()==lado2.top2()){
							if(lado2.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado2.top()-'0');
								aux+=(lado2.top2()-'0');
							}
							
						}
						if(lado3.top()==lado3.top2()){
							if(lado3.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado3.top()-'0');
								aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()==lado4.top2()){
							if(lado4.top()==' '){
								aux+=0;
							}else{
								aux=aux+(lado4.top()-'0');
								aux+=(lado4.top2()-'0');
							}
						}
						if(lado1.top()!=lado1.top2()){
							if(lado1.top()==' ' && lado1.top2()!=' '){
								aux=aux+0;
							}else if(lado1.top()!=' ' && lado1.top2()==' '){
								aux=aux+(lado1.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado1.top()-'0');
								//aux+=(lado1.top2()-'0');
							}
						}
						if(lado2.top()!=lado2.top2()){
							if(lado2.top()==' ' && lado2.top2()!=' '){
								aux=aux+0;
							}else if(lado2.top()!=' ' && lado2.top2()==' '){
								aux=aux+(lado2.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado2.top()-'0');
								//aux+=(lado2.top2()-'0');
							}
						}
						if(lado3.top()!=lado3.top2()){
							if(lado3.top()==' ' && lado3.top2()!=' '){
								aux=aux+0;
							}else if(lado3.top()!=' ' && lado3.top2()==' '){
								aux=aux+(lado3.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado3.top()-'0');
								//aux+=(lado3.top2()-'0');
							}
						}
						if(lado4.top()!=lado4.top2()){
							if(lado4.top()==' ' && lado4.top2()!=' '){
								aux=aux+0;
							}else if(lado4.top()!=' ' && lado4.top2()==' '){
								aux=aux+(lado4.top()-'0');
								//	aux+=(lado1.top2()-'0');
							}else{
								aux=aux+(lado4.top()-'0');
								//aux+=(lado4.top2()-'0');
							}						
						}
						cout<<"AUX: "<<aux<<endl;
						if(aux%5==0) pontoDupla2=pontoDupla2+aux;
					}
				}
			}

		}
		//system("clear");
		//if(errou==true && p>=2 && p<=4) cout<<"Jogador "<<p-1<<" PASSOU!"<<endl;
		//if(p==1 && errou==true) cout<<"Jogador 4 PASSOU!"<<endl;
		errou=false;
		jogou = false;
		passou=false;
		valida=false;
		cout<<"Carroça: "<<carroca.top()<<"|"<<carroca.top()<<endl;
		cout<<"\nlado1:"<<" ";
		lado1.imprime();
		cout<<"\n\nlado2:"<<" ";
		lado2.imprime();
		cout<<"\n\nlado3:"<<" ";
		lado3.imprime();
		cout<<"\n\nlado4:"<<" ";
		lado4.imprime();
		contador=0;
		cout<<endl;
		cout<<"AUX3: "<<aux3<<endl;
		cout<<"\npontoDupla1: "<<pontoDupla1<<endl;
		cout<<"\npontoDupla2: "<<pontoDupla2<<endl;
		if(qtd1==7){
		 	cout<<"Jogador 1 Ganhou!!!"<<endl;
		 	break;
		}
		if(qtd2==7) {
			cout<<"Jogador 2 Ganhou!!!"<<endl;
			break;
		}
		if(qtd3==7) {
			cout<<"Jogador 3 Ganhou!!!"<<endl;
			break;
		}
		if(qtd4==7) {
			cout<<"Jogador 4 Ganhou!!!"<<endl;
			break;
		}
		cont++;
		aux=0;
		aux2=0;
		aux3=0;
		jogada=0;
	}
}
