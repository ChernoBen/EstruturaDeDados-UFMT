#include <stdio.h>
#include <stdlib.h>

struct estru_no{
  int valor;//espaco para guardar valor
  struct estru_no *prox;//guarda endereco para outra estrutura
  struct estru_no *ant;
};
typedef struct estru_no tipo_no;

tipo_no *alocaNovoNo(int vl);

//inserções
void insereFim(tipo_no **ls,int vl);
//remocoes
int removeInicio(tipo_no **ls);
//impressoes
void imprimeLista(tipo_no *ls);
//---------------------------
int main(){
  tipo_no *lista;
  lista = NULL;
  
  // insereFim(&lista, 1);
  // imprimeLista(lista);
  // printf("removido : %d\n",removeInicio(&lista));
  // imprimeLista(lista);

  int i;
  for(i=0;i<18;i++){
    insereFim(&lista, i);
  }

  imprimeLista(lista);

  for(i=0;i<18;i++){
    printf("removido : %d\n",removeInicio(&lista));
  }
  return 1;
}

//------------------------

int removeInicio(tipo_no **ls){
  tipo_no *aux;
  int vl;
  if((*ls)->prox!=NULL){
    vl = (*ls)->prox->valor;
    aux = (*ls)->prox;
    (*ls)->prox = (*ls)->prox->prox;
    if((*ls)->prox !=NULL){
      (*ls)->ant = (*ls);
    }
    free(aux);
    return vl;
  }else{
    printf("[error]lista vazia");
    return -1;
  }
}

void insereFim(tipo_no **ls,int vl){
  tipo_no *aux,*novo_no;
  int count =0;
  if((*ls)==NULL){
    (*ls) = alocaNovoNo(vl);
  }else{
    aux = (*ls);
    while(aux->prox !=NULL){
      aux = aux->prox;
      count ++;
    }
    if(count==0){
      novo_no = alocaNovoNo(vl);
      novo_no->ant = aux;
      aux->prox = novo_no;
    }else{
      int val = aux->valor;
      novo_no = alocaNovoNo(aux->valor);
      aux->valor = vl;
      aux->prox = novo_no;
    } 
  }
}

void imprimeLista(tipo_no *ls){
  printf("inicio ->[");
  while(ls !=NULL){
    printf(" %d ", ls->valor);
    ls = ls->prox;
  }
  printf("]\n");
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
  novo_no->ant = NULL;
  //#4 retornar endereco de memoria do ponteiro criado
  return novo_no;
}