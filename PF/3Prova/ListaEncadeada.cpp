#include <iostream>
using namespace std;
typedef struct Tno{
    int dado;
    struct Tno*prox;
}no;
class Lista{
    no*inicio;
public:
    Lista(){
        inicio=NULL;
    }
    ~Lista(){
        no*aux=inicio,*aux2;
        while(aux!=NULL){
            aux2=aux;
            aux=aux->prox;
            delete aux2;
        }
    }
    void insIni(int val){
        no* aux = new no;
        aux->dado=val;
        aux->prox=inicio;
        inicio=aux;
    }

    void insereFinal(int val){
		no* aux=new no;
		no *ult = inicio;
		aux->dado=val;
		aux->prox=NULL;
		if(ult==NULL){
			inicio=aux;
		}else{
			while(ult->prox!=aux){
				ult=ult->prox;
			}
			ult->prox=aux;
		}
    }
    
    void RemoveIni(){
        no* aux=inicio;
        if(inicio!=NULL){
            inicio=inicio->prox;
            delete aux;
        }
    }
    void removeFim(){
		no* aux =inicio;
		if(inicio!=NULL){
			if(inicio->prox==NULL){
				delete inicio;
				inicio=NULL;
			}else{
		    	while(aux->prox->prox!=NULL){
					aux=aux->prox;
				}
				delete aux->prox;
				aux->prox=NULL;
			}
		}
	}
};

void Concat(Lista l1, Lista l2){
    no*aux=l2.inicio;
    for(aux;aux!=NULL;aux=aux->prox){
        l1.insereFinal(aux->val);
    }
}

void Concat2(Lista l1, Lista l2){
    no* aux=l1.inicio;
    for(aux;aux!=NULL;aux=aux->prox){
        aux->prox=l2.inicio;
    }
}

void ConcatLC(Lista l1, Lista l2){
    no* aux=l1.inicio;
    for(aux;aux!=NULL;aux=aux->prox)
        aux->prox=l2.inicio;
    aux=l1.inicio;
    for(aux;aux!=NULL;aux=aux->prox)
        aux->prox=l1.inicio;
}

No* intercala(no* l1, no*l2){
    no*a1,*a2,*r=l1;
    if(l1==NULL) return l2;
    while(l1!=NULL && l2!=NULL){
        a1=l1->prox;
        l1->prox=l2;
        a2=l2->prox;
        l2->prox=a1;
        l1=a1;
        l2=a2;
    }
    return r;    
}
void insereOrd(int val){
    no* aux=new no;
    aux->dado=val;
    if(inicio==NULL){
       inicio=aux;
       aux->prox=NULL;
    }else if(val < inicio->dado){
        aux->prox=inicio;
        inicio=aux;
    }else{
        no*procura = inicio;
        while(procura->prox!=NULL && val>procura->prox->dado){
            procura = procura->prox;
        }
        aux->prox=procura->prox;
        procura->prox=aux;
    }
}
int main(){
    
}