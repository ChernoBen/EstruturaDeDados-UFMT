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
void inserePosicao(tipo_no **ls,int vl,int pos);
void insereInicio(tipo_no **ls,int vl);
void insereFim(tipo_no **ls,int vl);
//remocoes
int removeInicio(tipo_no **ls);
int removeFim(tipo_no **ls);
int removePosicao(tipo_no **ls,int pos);
//impressoes
void imprimeLista(tipo_no *ls);
//quetao1
void concatena(tipo_no *l1,tipo_no *l2,tipo_no **l3);

//---------------------------
int main(){
  tipo_no *l1,*l2,*l3;
  l1 = NULL;
  l2 = NULL;
  l3 = NULL;
  insereFim(&l1, 0);
  insereFim(&l1, 1);
  insereFim(&l1, 2);
  insereFim(&l1, 3);
  imprimeLista(l1);
  insereFim(&l2, 4);
  insereFim(&l2, 5);
  insereFim(&l2, 6);
  insereFim(&l2, 7);
  //insereFim(&l2, 8);
  imprimeLista(l2);
  concatena(l1,l2,&l3);
  imprimeLista(l3);
  
  return 1;
}

//------------------------
void concatena(tipo_no *l1,tipo_no *l2,tipo_no **l3){
  tipo_no *lConcatenada;
  while(l1 != NULL){
    printf("%d\n",l1->valor);
    insereFim(l3, l1->valor);
    l1 = l1->prox;
  }
  while(l2!=NULL){
    printf("l2:%d\n",l2->valor);
    insereFim(l3,l2->valor);
    l2 = l2->prox;
  }
}
//---------------------
void inserePosicao(tipo_no **ls,int vl,int pos){
  tipo_no *novo_no,*aux,*aux2;
  int contador;
  if(pos == 0){
    insereInicio(ls, vl);
  }else{
    aux = (*ls);
    contador = 0;
    while((aux != NULL)&&(contador<pos)){
      aux2 = aux;
      aux = aux->prox;  
      contador++;
    }
    if((aux != NULL) && (contador == pos)){
      novo_no = alocaNovoNo(vl);
      novo_no->prox = aux;
      novo_no->ant = aux2;
      aux2->prox = novo_no;
    }else if((aux == NULL)&&(contador == pos)){
      //insere no final
      novo_no = alocaNovoNo(vl);
      novo_no->ant = aux2;
      novo_no->prox = NULL;
      aux2->prox = novo_no;
    }else{
      printf("[error] posicao inválida\n");
    }
  }
}

int removePosicao(tipo_no **ls,int pos){
  tipo_no *aux,*aux2;
  if((*ls)!=NULL){
    int contador,vl;
    if(pos == 0){
      return removeInicio(ls);
    }else{
      aux = (*ls);
      contador = 0;
      while((aux!=NULL) && (contador < pos)){
        aux2 = aux;
        aux = aux->prox;
        contador++;
      }
      if(aux !=NULL){
        vl = aux->valor;
        aux2->prox = aux->prox;
        aux2->ant = aux->ant;
        free(aux);
        return vl;
      }else{
        printf("[error] posicao inválida");
        return -1;
      }
    }
  }else{
    printf("[error]lista vazia\n");
    return -1;
  } 
}

int removeInicio(tipo_no **ls){
  tipo_no *aux;
  int vl;
  if((*ls)!=NULL){
    vl = (*ls)->valor;
    aux = (*ls);
    (*ls) = (*ls)->prox;
    if((*ls) !=NULL){
      (*ls)->ant = NULL;
    }
    free(aux);
    return vl;
  }else{
    printf("[error]lista vazia");
    return -1;
  }
}

int removeFim(tipo_no **ls){
  tipo_no *aux;
  int vl;
  if((*ls)!=NULL){
    aux = (*ls);
    while(aux->prox!=NULL){
      aux = aux->prox;
    }
    vl = aux->valor;
    if(aux->ant !=NULL){
      aux->ant->prox=NULL;
    }
    //verifica se é o ultimo no
    if(((*ls)->ant == NULL)&&((*ls)->prox == NULL)){
      (*ls) = NULL;
    }
    free(aux);
    return vl;
  }else{
    printf("[error] lista vazia");
    return -1;
  }
}

void insereFim(tipo_no **ls,int vl){
  tipo_no *aux,*novo_no;
  if((*ls)==NULL){
    //se lista vazia aloque um novo no;
    (*ls) = alocaNovoNo(vl);
  }else{
    aux = (*ls);
    while(aux->prox !=NULL){
      aux = aux->prox;
    }
    novo_no = alocaNovoNo(vl);
    novo_no->ant = aux;
    aux->prox = novo_no;
  }
}

void insereInicio(tipo_no **ls,int vl){
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  //novo nó se torna a cabeça da estrutura
  novo_no->prox = (*ls);
  if((*ls)!=NULL){
    (*ls)->ant = novo_no;
  }
  //pontiro agora guarda novo_no apontando para o elemento que era a antiga cabeça
  (*ls) = novo_no;
}

//F de impressao
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