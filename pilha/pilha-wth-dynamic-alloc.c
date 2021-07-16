#include <stdio.h>
#include <stdlib.h>

struct estru_no{
  int valor;//espaco para guardar valor
  struct estru_no *prox;//guarda endereco para outra estrutura
};
typedef struct estru_no tipo_no;

struct estru_resultado{
  int valor;
  tipo_no *no;
};

typedef struct estru_resultado tipo_resultado;

tipo_no *alocaNovoNo(int vl);

//empilha
tipo_no *empilha(tipo_no *pl,int vl);

//desempilha

tipo_resultado desempilha(tipo_no *pl);

//imprime
void imprimePilha(tipo_no *pl);
//-------------------------------

int main(){
  tipo_no *pilha;
  pilha = NULL;
  tipo_resultado result;

  //chamadas
  pilha = empilha(pilha, 4);
  pilha = empilha(pilha, 2);
  pilha = empilha(pilha, 0);
  imprimePilha(pilha);
  result = desempilha(pilha);
  pilha = result.no;
  imprimePilha(pilha);
  return 1;
}

//funcao de alocação
tipo_no *alocaNovoNo(int vl){
  //#1 criar um ponteiro tipo_no
  tipo_no *novo_no;
  //#2 alocar um espaco na memoria
  novo_no = (tipo_no*) malloc(sizeof(tipo_no));
  //#3 inicializar
  novo_no->valor = vl;
  novo_no->prox = NULL;
  //#4 retornar endereco de memoria do ponteiro criado
  return novo_no;
}

//funcao que empilha
tipo_no *empilha(tipo_no *pl,int vl){
  //# 1 cria um novo nó(alocar)
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  //# 2 conectar estrutura antiga atras da nova estrutura
  novo_no->prox = pl;
  return novo_no;
}

// funcao que desempilha
tipo_resultado desempilha(tipo_no *pl){
  //guarda o valor a ser retornado
  tipo_resultado result;
  result.valor = pl->valor;//valor que sera removido
  result.no = pl->prox;
  //nó a ser removido
  tipo_no *topo;
  topo = pl;
  //desalocar original
  free(topo);
  return result;

}

void imprimePilha(tipo_no *pl){
  if(pl == NULL){
    printf("[Error] pilha vazia");
  }else{
    printf("topo->[");
    while(pl != NULL){
      printf("[%d] ",pl->valor);
      pl = pl->prox;
    }
    printf("]<-base\n");
  }
}