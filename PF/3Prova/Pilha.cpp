#include <iostream>
using namespace std;
typedef struct Tno{
    int dado;
    struct Tno *prox;
}no;
class Pilha{
    no*topo;
public:
    Pilha(){
        topo=NULL;
    }
    ~Pilha(){
        no* aux=topo,*aux2;
        while(aux!=NULL){
            aux2=aux;
            aux=aux->prox;
            delete aux2;
        }
    }  
    int vazia(){
        if(topo==NULL) return 1;
        else return 0;
    }
    void push(int val){
        no*aux = new no;
        aux->dado=val;
        aux->prox=topo;
        topo=aux;
    }
    int pop(){
        int res=0;
        if(!vazia()){
            no* aux = topo;
            topo=topo->prox;
            res=aux->dado;
            delete aux;
            return res;
        }
    }
    void imprime(){
        no* aux;
        for(aux=topo;aux!=NULL;aux=aux->prox){
            cout<<aux->dado<<" ";
        }
    }
};
int main(){

}