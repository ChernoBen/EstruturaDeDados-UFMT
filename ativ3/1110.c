#include <stdio.h>
#include <stdlib.h>

struct estru_no{
  int valor;//espaco para guardar valor
  struct estru_no *prox;//guarda endereco para outra estrutura
};
typedef struct estru_no tipo_no;

tipo_no *alocaNovoNo(int vl);


//insere inicio
void insereInicio(tipo_no **ls,int vl);
//insere fim
void insereFim(tipo_no **ls,int vl);

//-------------------------------

//remove inicio
int removeInicio(tipo_no **ls);
//remove fim
int removeFim(tipo_no **ls);

int main(){
  int entrada;
  int status = 1;
  while(status ==1){
    scanf("%d", &entrada);
    if (entrada == 0 || entrada > 50){
      status = 0;
    }else{
      tipo_no *baralho;
      baralho = NULL;
      int i;
      for(i=entrada; i>0; i--){
        insereInicio(&baralho,i);
      }
      printf("Discarded cards:");
      int j;
      for(j=0;j<entrada-1;j++){
        if(j>0)printf(",");
        printf(" %d",removeInicio(&baralho));
      }
      printf("\n");
      printf("Remaining card: %d\n",baralho->valor);
    }
  }
  return 0;
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

// URI
int removeInicio(tipo_no **ls){
  tipo_no *aux,*aux2;
  int vl;
  if((*ls)!=NULL){
    aux = (*ls);//1
    aux2 = aux->prox;//2
    vl = (*ls)->valor;//1
    insereFim(ls,aux2->valor);//2
    (*ls) = aux2->prox;//3
    free(aux);
    free(aux2);
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