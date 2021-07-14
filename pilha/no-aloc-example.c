#include <stdio.h>
#define N 10

//FIRST IN LAST OUT

/*
 ---metodos---
 #1 - funçao de insercao
 #2 - funçao de remoçao
 #3 - funcao que guarda o ultimo elemento de entrada(topo)
*/

struct est_pilha{
  int pilha[N];
  int contador;
};
typedef struct est_pilha tipo_pilha;

void inicializaPilha(tipo_pilha *pl);
void empilha(tipo_pilha *pl, int valor);
int desempilha(tipo_pilha *pl);
void imprimePilha(tipo_pilha pl);
int top(tipo_pilha pl);

int main(){
  tipo_pilha pilha;
  inicializaPilha(&pilha);
  empilha(&pilha,1);
  empilha(&pilha,3);
  empilha(&pilha,5);
  imprimePilha(pilha);
  desempilha(&pilha);
  imprimePilha(pilha);
  printf("%d\n",top(pilha));
  return 1;
}

int top(tipo_pilha pl){
  if( pl.contador > 0){
    return pl.pilha[pl.contador-1];
  }else{
    printf("[Error] pilha vazia\n");
    return -1;
  }
}

void imprimePilha(tipo_pilha pl){
  if( pl.contador > 0){
    printf("[");
    for(int i=0; i<pl.contador;i++){
      printf(" %d ",pl.pilha[i]);
    }
    printf("]\n");
  }else{
    printf("[Error] pilha vazia\n");
  }
}

int desempilha(tipo_pilha *pl){
  if(pl->contador > 0){
    /*
    Nao precisa apagar, apenas mostrar o array 
    ate o ponto antes do ultimo item que deve ser removido
    */
    return  pl->pilha[ --pl->contador];
  }else{
    printf("[error] pilha vazia\n");
    return -1;
  }
}

void empilha(tipo_pilha *pl,int valor){
  if (pl->contador < N){
    pl->pilha[pl->contador] = valor;
    pl->contador++;
  }else{
    printf("[Error] pilha cheia\n");
  }
}

void inicializaPilha(tipo_pilha *pl){
  pl->contador = 0;
}