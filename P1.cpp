//Questão 1
#include <iostream>
using namespace std;
int Fatorial(int num);
int main(){
	int num=0;
	cin>>num;
	cout<<"Fatorial de "<<num<<": "<<Fatorial(num)<<endl;
}

int Fatorial(int num){
	int fat=1, cont;
	if(num>0){
		for(cont=num;cont>=1;cont--){
			fat = fat*cont;
		}
	}
	return fat;
}