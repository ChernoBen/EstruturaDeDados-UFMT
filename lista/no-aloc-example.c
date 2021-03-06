#include <stdio.h>
#define N 10

//Nao possui restricoes de entrada ou saida
//insere e remove pelo mesmo lado

/*
remoçao trabalha igual remocao de fila
*/

struct est_lista{
  int lista[N];
  int contador;
};
typedef struct est_lista tipo_lista;

void inicializaLista(tipo_lista *ls);
void insereFim(tipo_lista *ls, int valor);
void insereInicio(tipo_lista *ls,int valor);
void inserePosicao(tipo_lista *ls, int valor, int posicao);
void imprimeLista(tipo_lista ls);
int removeFim(tipo_lista *ls);
int removeInicio(tipo_lista *ls);
int removePosicao(tipo_lista *ls, int posicao);
int main(){
  tipo_lista lista;
  
  inicializaLista(&lista);
  insereFim(&lista,8);
  insereFim(&lista,9);
  imprimeLista(lista);
  insereInicio(&lista, 5);
  insereInicio(&lista, 2);
  imprimeLista(lista);
  inserePosicao(&lista,10,4);
  inserePosicao(&lista, 20, 5);
  inserePosicao(&lista, 11, 2);
  inserePosicao(&lista,3, 2);
  imprimeLista(lista);
  //remocoes
  printf("remove inicio %d\n",removeInicio(&lista));
  imprimeLista(lista);
  printf("remove fim %d\n",removeFim(&lista));
  imprimeLista(lista);
  printf("remove posicao %d\n",removePosicao(&lista,2));
  imprimeLista(lista);

  return 1;
}

int removePosicao(tipo_lista *ls, int posicao){
  if(ls->contador > 0 ){
    if((posicao>=0)&&(posicao<ls->contador)){
      int aux,i;
      aux = ls->lista[posicao];
      for (i=posicao;i < ls->contador-1; i++){
        ls->lista[i] = ls->lista[i+1];
      }
      ls->contador--;
      return aux;
    }else{
      printf("[error] posicao invalida\n");
      return -1;
    }
  }else{
    printf("[erro] lista vazia\n");
    return -1;
  }
}

int removeInicio(tipo_lista *ls){
  if(ls->contador > 0 ){
    int aux,i;
    aux = ls->lista[0];
    for (i=0;i<ls->contador-1;i++){
      ls->lista[i] = ls->lista[i+1];
    }
    ls->contador--;
    return aux;
  }else{
    printf("[erro] lista vazia\n");
    return -1;
  }
}

int removeFim(tipo_lista *ls){
  if(ls->contador > 0){
    return ls->lista[--ls->contador];
  }else{
    printf("[error] lista vazia\n");
    return -1;
  }
}

void imprimeLista(tipo_lista ls){
  printf("lista [");
  int i;
  for (i=0;i<ls.contador;i++){
    printf(" %d ",ls.lista[i]);
  }
  printf("]\n");
}

void inicializaLista(tipo_lista *ls){
  ls->contador = 0;
}

//insere posicao especifica
void inserePosicao(tipo_lista *ls, int valor, int posicao){
  if(ls->contador < N){
    if((posicao >=0) &&(posicao <= ls->contador)){
      //verificar se posicao == 0 se for chamar insere inicio
      //verificar se posicao == contador se for chamar insere fim
      int i;
      for (i=ls->contador-1; i >= posicao; i--){
        ls->lista[i+1] = ls->lista[i];
      }
      ls->lista[i+1] = valor;
      ls->contador ++;
    }
  }else{
    printf("lista cheia");
  }
} 
//insere no inicio
void insereInicio(tipo_lista *ls, int valor){
  /*
    - valor vai pra primeira posição
    - demais valores vao para a proxima posicao
    - ex: valo[0] vai pra 1 valor[1] vai pra valor[2]
  */
  if(ls->contador < N){
    int i;
    for (i=ls->contador; i>0;i--){
      ls->lista[i] = ls->lista[i-1];
    }
    ls->lista[0] = valor;
    ls->contador++;
  }else{
    printf("[error] lista cheia\n");
  }
}
//insere no fim da lista
void insereFim(tipo_lista *ls, int valor){
  if(ls->contador < N){
    ls->lista[ls->contador++] = valor;
  }else{
    printf("[error] lista cheia\n");
  }
}