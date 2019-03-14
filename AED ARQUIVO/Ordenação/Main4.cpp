#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void inverte(string vet[], int tam){
string temp = "";
  for(int i = 0; i < tam/2; i++){
    temp = vet[i];
    vet[i] = vet[tam-1-i];
    vet[tam-1-i] = temp;
  }
}

int retorna(string palavra){//Retorna o numero apos a #.
  int i, j, limite = 0,tamanho = palavra.size();
  char numero[30];
  for(i = 0; i < tamanho; i++){
    if(palavra[i] == '#'){
      i++;
      for(j = 0; j < tamanho - i; j++){
        numero[j] = palavra[i+j];
        limite++;
      }
    }
  }
  int num = atoi(numero);
  return num;
}

void ordena(string vet[], int esq, int dir){//Ordena o vetor de strings.
      int i = esq, j = dir;
      string temp;
      int pivo;
      int aux = (esq + dir) / 2;
      pivo = retorna(vet[aux]);
      while (i <= j) {
            while (retorna(vet[i]) < pivo)
                  i++;
            while (retorna(vet[j]) > pivo)
                  j--;
            if (i <= j) {//Troca as strings de posicao, se um numero de view for maior que o outro.
                  temp = vet[i];
                  vet[i] = vet[j];
                  vet[j] = temp;
                  i++;
                  j--;
            }
      }
      if (esq < j)
            ordena(vet, esq, j);
      if (i < dir)
            ordena(vet, i, dir);
}

int main(int argc, char* argv[]){
  int i = 0;
  string linha;
  ifstream arq;
  ofstream arqs;
  string vet[2093];
    arq.open(argv[1], ios::in);//Abrindo arquivo de entrada.
    if(arq.is_open()){//verificando se foi aberto o arquivo.
      while(getline(arq,linha)){
        vet[i] = linha;
        i++;
      }
    }else{
        cout<<"Erro de abertura do arquivo de entrada!\n";
      }
      arq.close();//Fechando o arquivo.
//mexendo no vetor, para depois armazenar no arquivo.
ordena(vet, 0, 2092-1);
inverte(vet, 2092);
//Começando a mexer nos arquivos.
    arqs.open("ConsultasFinal.txt", ios::out);//Abrindo/Criando arquivo para saída organizada.
     if(arqs.is_open()){
      for(int i = 0; i < 2092; i++){//Guardar todas as informações da estrututa no arquivo de saida. 
        if(i == 2091)
          arqs<<vet[i];
        else
        arqs<<vet[i]<<endl;
      }
      arqs.close();
      }else{
      cout<<"Erro de abertura do arquivo de saída!\n";
      }
}