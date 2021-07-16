#include <stdio.h>
#include <stdlib.h>

struct estru_no{
  int valor;//espaco para guardar valor
  struct estru_no *prox;//guarda endereco para outra estrutura
};
typedef struct estru_no tipo_no;

//criar uma função so para alocar um novo espaco na memoria
tipo_no *alocaNovoNo(int vl);
//funcao de inserção de nó na estrutura
void insereFinal(tipo_no **fl,int vl);
//funcao de impressao
void imprimeFila(tipo_no *fl);
//funcao de inserção com retorno
tipo_no *insereFinal2(tipo_no *fl, int vl);
//funcao que remove um elemento da estrutura
int removeInicio(tipo_no **fl);
// segunda estrategia de remoção
tipo_no *removeInicio2(tipo_no *fl);
//-------------------------------

int main(){
  tipo_no *fila;
  fila = NULL;
  insereFinal(&fila, 7);
  insereFinal(&fila, 10);
  insereFinal(&fila, 3);
  //segunda estratégia de inserção utilizando retorno
  fila = insereFinal2(fila,20);//funciona em filas NULL
  imprimeFila(fila);
  printf("Valor removido %d\n",removeInicio(&fila));
  //remocao 2 estrategia
  fila = removeInicio2(fila);
  imprimeFila(fila);
  return 1;
}

//funcao de alocação de memoria
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
//------------------inserções------------------
void insereFinal(tipo_no **fl,int vl){
  //#1 alocar um novo no na memoria
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  //verifica se fila está vazia
  if((*fl)==NULL){
    // se vazio fl(fila) recebe um primeiro elemento
    (*fl) = novo_no;
  }else{
    tipo_no *aux;
    aux = (*fl);//aponta para o primeio elemento da estrutura
    //Se nao vazio percorra até o ultimo item
    while(aux->prox !=NULL){
      aux = aux->prox;
    }
    //aux->proximo == NULL signfica que este é o ultimo elemento da fila
    aux->prox = novo_no;
  }
}

//funcao que insere novo valor e retorna o endereco do primeiro nó
tipo_no *insereFinal2(tipo_no *fl, int vl){
  //#1 alocar um novo nó
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  //ponteiro aux para alcancar ultimo elemento
  tipo_no *aux;
  if(fl == NULL){
    //se fila vazia retorne endereco do novo nó alocado
    return novo_no;
  }else{
    //se nao vazia aux recebe o elemento principal da estrutura
    aux = fl;
    while(aux->prox !=NULL){
      //enquando elemento.proximo for diferente de NULL, percorra a estrutura até chegar no ultimo elemento
      aux = aux->prox;
    }
    // Ultimo elemento encontrado então ensida na chave "prox" o "novo_no"
    aux->prox = novo_no;
    return fl;
  }
}

//-------------remoções--------------------

int removeInicio(tipo_no **fl){
  tipo_no *aux;
  int vl;
  //#1 verificar se estrutura esta vazia
  if((*fl) != NULL){
    //guardar o valor que será removido
    aux = (*fl);
    vl = aux->valor;
    //atualizar a estrutura para ter o segundo elemento como principal
    (*fl) = (*fl)->prox;
    // liberar a memoria do espaço que nao utiliza mais
    free(aux);
    return vl;
  }else{
    return -1;
  }
}

tipo_no *removeInicio2(tipo_no *fl){
  tipo_no *aux;
  //#1 verificar se estrutura esta vazia
  if(fl != NULL){
    //guardar o valor que será removido
    aux = fl;
    //atualizar a estrutura para ter o segundo elemento como principal
    fl = fl->prox;
    // liberar a memoria do espaço que nao utiliza mais
    free(aux);
    return fl;
  }else{
    return NULL;
  }
}

//imprime todos elementos da estrutura
void imprimeFila(tipo_no *fl){
  printf("Saida->[");
  while(fl !=NULL){
    printf("[%d] ",fl->valor);
    fl = fl->prox;
  }
  printf("]<-entrada\n");
}
