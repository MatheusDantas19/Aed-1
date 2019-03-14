#include <iostream>
using namespace std;
typedef struct Tno{
    int dado;
    struct Tno *prox;
}no;
class Fila{
    no*inicio,*fim;
    Fila(){
        inicio=NULL;
        fim=NULL;
    }
    ~Fila(){
        no*aux=inicio,*aux2;
        if(aux!=NULL){
            aux2=aux;
            aux=aux->prox;
            delete aux2;
        }
    }
    int vazia(){
        if(inicio==NULL) return 1;
        else return 0;
    }
    void push(int val){
        no* aux = new no;
        aux->dado=val;
        if(!vazia()){
            fim->prox=aux;
        }else{
            inicio=aux;
        }
        fim=aux;
    }
    int pop(){
        int res=0;
        no*aux=inicio;
        if(!vazia()){
            inicio=inicio->prox;
            res=aux->dado;
            delete aux;
        }
        if(inicio==NULL){
			fim=NULL;
        }
        return res;
    }
    void limpar(){
		if(!vazia()){
			while(inicio != NULL){
				pop();
			}
		} else {
			cout<<"Fila vazia"<<endl;
		}
	}
	void imprime(){
		no* aux;
		aux = inicio;
		while(aux!=NULL){
			cout<<aux->dado<<" ";
			aux = aux->prox;
		}
		cout<<endl;
	}
};
int main(){
    
}