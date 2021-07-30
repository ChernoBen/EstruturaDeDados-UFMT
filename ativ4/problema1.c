#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 1000
typedef struct item{
  char tipo;
}TipoItem;

typedef struct pilha {
  TipoItem item[max];
  int topo;
}Pilha;

//prototipos
void criarPilha(Pilha *pl);
void empilha(Pilha *pl,TipoItem c);
int taVazia(Pilha pl);
void desempilha(Pilha *pl,TipoItem *x);
int prioridade(char a,char b);
void imprime(Pilha *pl);

int main(){
  int counter =0;
  Pilha pl;
  criarPilha(&pl);
  TipoItem elemento,pop;
  char funcao[max];
  int i,j;
  int p = prioridade('a','b');
  printf("%d\n",p);
  
  //regex pra processar entrada
  scanf("%[^\n]",funcao);
  for (i=0;i<strlen(funcao);i++){
    elemento.tipo = funcao[i];
    if((elemento.tipo == '-') || (elemento.tipo == '+') || (elemento.tipo == '/') || (elemento.tipo == '^') || (elemento.tipo == '*') || (elemento.tipo == '(') || (elemento.tipo == ')')){
      if((pl.topo == 0)|| (elemento.tipo == '(')){
        empilha(&pl,elemento);
      }else if((pl.topo == 0)||(elemento.tipo==')')){
        while((pl.topo>0)&&(pop.tipo!='(')){
          //printf("--\n");
          imprime(&pl);
          desempilha(&pl,&pop);
        }
        desempilha(&pl, &pop);
      }else{
        while(pl.topo>0){
          //printf("----2---\n");
          imprime(&pl);
          desempilha(&pl,&pop);
        }
        empilha(&pl,elemento);
      }
    }else{
      printf("%c\n",elemento.tipo);
    }
  }
  while(pl.topo>0){
    //printf("---fim-----\n");
    imprime(&pl);
    desempilha(&pl,&pop);
  }
  return 0;
}

//funções

void criarPilha(Pilha *pl){
  pl->topo=0;
}

void empilha(Pilha *pl,TipoItem c){
  if(pl->topo == max){
    printf("Pilha cheia.\n");
    return;
  }else{
    pl->item[pl->topo] = c;
    pl->topo++;
  }
}

int taVazia(Pilha pl){
  return (pl.topo == 0);
}

void desempilha(Pilha *pl,TipoItem *x){
  char c;
  if(taVazia(*pl)){
    return;
  }else{
    *x = pl->item[pl->topo-1];
    pl->topo--;
  }
}

int prioridade(char a,char b){
  if('a'<='c'){
    return 1;
  }else{
    return 0;
  }
}

//imprime
void imprime(Pilha *pl){
  TipoItem element;
  int *tes;
  if(pl->topo ==0){
    printf("Pilha vazia.\n");
  }else{
    int i;
    for(i = 0;i < pl->topo; i++){
      element = pl->item[i]; 
      printf("%c",element.tipo);
    }
  }
}