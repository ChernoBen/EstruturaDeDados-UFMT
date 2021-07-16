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

//insere na posicao
void inserePosicao(tipo_no **ls,int vl,int pos);
//insere inicio
void insereInicio(tipo_no **ls,int vl);
//insere fim
void insereFim(tipo_no **ls,int vl);
//imprime
void imprimeLista(tipo_no *ls);
//-------------------------------
//remove posicao
int removePosicao(tipo_no **ls,int pos);
//remove inicio
int removeInicio(tipo_no **ls);
//remove fim
int removeFim(tipo_no **ls);

int main(){
  tipo_no *lista;
  lista = NULL;
  insereFim(&lista,6);
  insereInicio(&lista, 7);
  insereInicio(&lista, 8);
  insereInicio(&lista, 9);
  insereInicio(&lista, 10);
  insereInicio(&lista, 11);
  insereInicio(&lista, 12);
  insereInicio(&lista, 13);
  imprimeLista(lista);
  inserePosicao(&lista,0,1);
  inserePosicao(&lista,0,5);
  imprimeLista(lista);
  printf("removido -> %d\n",removeInicio(&lista));
  printf("removido -> %d\n",removeFim(&lista));
  imprimeLista(lista);
  printf("valor remivido: %d\n",removePosicao(&lista,1));
  imprimeLista(lista);
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

//funcao que insere elemento no inicio
void insereInicio(tipo_no **ls,int vl){
  //# 1 cria um novo nó(alocar)
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  //# 2 conectar estrutura antiga atras da nova estrutura
  novo_no->prox = (*ls);
  (*ls) = novo_no; 
}
// insere na posicao
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
      aux2->prox = novo_no;
    }else if((aux == NULL)&&(contador == pos)){
      //insere no final
      novo_no = alocaNovoNo(vl);
      aux2->prox = novo_no;
    }else{
      printf("[error] posicao inválida\n");
    }
  }
}
//insere final 
void insereFim(tipo_no **ls,int vl){
  //#1 alocar um novo no na memoria
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  //verifica se lista está vazia
  if((*ls)==NULL){
    // se vazio ls(lista) recebe um primeiro elemento
    (*ls) = novo_no;
  }else{
    tipo_no *aux;
    aux = (*ls);//aponta para o primeio elemento da estrutura
    //Se nao vazio percorra até o ultimo item
    while(aux->prox !=NULL){
      aux = aux->prox;
    }
    //aux->proximo == NULL signfica que este é o ultimo elemento da lista
    aux->prox = novo_no;
  }
}
// insere em posicao especifica

//-----------remoções-----------------
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
    aux = (*ls);
    vl = (*ls)->valor;
    (*ls) = (*ls)->prox;
    free(aux);
    return vl;
  }else{
    return -1;
  }
}

//remove fim
int removeFim(tipo_no **ls){
  tipo_no *aux,*aux2;
  int vl;
  if((*ls)!=NULL){
    aux = (*ls);
    while(aux->prox!=NULL){
      aux2 = aux;
      aux = aux->prox;
    }
    vl = aux->valor;
    free(aux);
    aux2->prox = NULL;
    return vl;
  }else{
    return -1;
  }
}
//-------------impressão---------------
void imprimeLista(tipo_no *ls){
  if(ls == NULL){
    printf("[Error] lista vazia");
  }else{
    printf("inicio->[");
    while(ls != NULL){
      printf("[%d] ",ls->valor);
      ls = ls->prox;
    }
    printf("]<-fim\n");
  }
}