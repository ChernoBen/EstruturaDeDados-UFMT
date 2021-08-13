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
//questao2
void liberaGeral(tipo_no **lst);
//questao3
void inverteLista(tipo_no **l4,tipo_no *l1);
//q4
void ordenaL (tipo_no *l1,tipo_no *l2,tipo_no **l3);
//qestao5
void intersec(tipo_no * l1,tipo_no *l2,tipo_no **l3);
//qestao7
int qtdLista(tipo_no *lista);
//questao8
tipo_no *retornaPonteiro(tipo_no *lista,int vl);
//questao9
void deslocaNo(tipo_no *no,int valor,int novaPosicao);
//questao 10
tipo_no *copiaLista(tipo_no *lista);

//---------------------------
int main(){
  //Problema 1
  /*
    Uma vantagem de listas encadeadas é que elementos podem ser adicionados indefinidamente(desconsiderando a memória da máquina),
  enquanto um array eventualmente ficará cheio ou terá que ser redimencionado. 
    Remover elementos de um array deixa espaços vazios enquanto em listas encadeadas os nós podem ser apagados
  liberando assim o espaço em memória que antes era ocupado por este nó.
    Uma desvantagem de listas encadeadas em comparação com arrays, é que enquanto arrays podem ceder acesso a todos seus índices sem uma ordem específica,
  listas encadeadas só permitem acesso sequencial, mesmo utilizando uma função que permite adicionar um elemento em uma posição determinada por um
  usuário, essa função terá que "navegar" através de cada nó até chegar na posição desejada.
  */
  //Problema 2   
  tipo_no *l1,*l2,*l3,*l4,*l5;
  l1 = NULL;
  l2 = NULL;
  l3 = NULL;
  l4 = NULL;
  l5 = NULL;
  //Q1
  printf("Q1----\n");
  insereFim(&l1, 0);
  insereFim(&l1, 1);
  insereFim(&l1, 2);
  insereFim(&l1, 3);
  insereFim(&l2, 4);
  insereFim(&l2, 5);
  insereFim(&l2, 6);
  imprimeLista(l1);
  insereFim(&l2, 7);
  //insereFim(&l2, 8);
  imprimeLista(l2);
  concatena(l1,l2,&l3);
  //Q2
  printf("Q2----\n");
  imprimeLista(l3);
  liberaGeral(&l3);
  imprimeLista(l3);
  //Q3
  printf("Q3-----\n");
  inverteLista(&l4,l1);
  imprimeLista(l4);
  //Q4
  liberaGeral(&l1);
  liberaGeral(&l2);
  printf("Q4-----\n");
  insereFim(&l1, 1);
  insereFim(&l1, 2);
  insereFim(&l1, 3);
  insereFim(&l1, 4);
  insereFim(&l1, 5);
  imprimeLista(l1);
  insereFim(&l2, 0);
  insereFim(&l2, 6);
  insereFim(&l2, 7);
  insereFim(&l2, 9);
  insereFim(&l2, 8);
  imprimeLista(l2);
  tipo_no *teste;
  teste = NULL;
  ordenaL(l1,l2,&teste);
  printf("Ordenada: ");
  imprimeLista(teste);
  liberaGeral(&l1);
  liberaGeral(&l2);
  //q5
  printf("Q5-----\n");
  insereFim(&l1, 1);
  insereFim(&l1, 2);
  insereFim(&l1, 3);
  insereFim(&l1, 4);
  insereFim(&l1, 9);
  printf("l1: ");
  imprimeLista(l1);
  insereFim(&l2, 5);
  insereFim(&l2, 2);
  insereFim(&l2, 3);
  insereFim(&l2, 1);
  insereFim(&l2, 0);
  printf("l2: ");
  imprimeLista(l2);
  intersec(l1,l2,&l5);
  imprimeLista(l5);
  //Q7
  printf("Q7------\nQuantidade de itens: %d\n",qtdLista(l5));
  //Q8
  printf("Q8------\n");
  tipo_no *result;
  result = NULL;
  result = retornaPonteiro(l5, 1);
  printf("Valor no pontiero igual a : %d\n",result->valor);
  //q10
  printf("Q10-----\n");
  tipo_no *copia;
  copia = copiaLista(l5);
  imprimeLista(copia);
  return 1;
}

//------------------------
tipo_no *copiaLista(tipo_no *lista){
  tipo_no *nova_lista;
  nova_lista = NULL;
  while(lista!=NULL){
    insereFim(&nova_lista,lista->valor );
    lista = lista->prox;
  }
  return nova_lista;
}
void deslocaNo(tipo_no *no,int valor,int novaPosicao){
  tipo_no *aux,*aux2,*aux3;
  aux3 = NULL; 
  aux = NULL;
  aux2 = no;
  int contador,vl,qtd,total;
  contador = 0;
  aux = no;
  while(aux!=NULL){
    if(aux->valor){
      vl = aux->valor;
      aux = aux->prox;
    }else{
      aux = aux->prox;
      contador ++;
    }
  }
  qtd = qtdLista(aux);
  int i;
  for(i = contador;i<qtd;i++){
    inserePosicao(&no,aux->valor,i);
  }
  inserePosicao(&no,vl,novaPosicao);
  removeFim(&no);
}

tipo_no *retornaPonteiro(tipo_no *lista,int vl){
  while(lista!=NULL){
    if(lista->valor==vl){
      return lista;
    }else{
      lista=lista->prox;
    }
  }
  return 0;
}
int qtdLista(tipo_no *lista){
  int contador = 0;
  while(lista !=NULL){
    lista = lista->prox;
    contador++;
  }
  return contador;
}
void intersec(tipo_no *l1,tipo_no *l2,tipo_no **l3){
  tipo_no *aux, *aux2;
  int contador,N;
  aux=l1;aux2=l2;
  while(aux != NULL){
    while(aux2 != NULL){
      if(aux->valor == aux2->valor){
        insereFim(l3,aux->valor);
      }
      aux2 = aux2->prox;
    }
    aux = aux->prox;
    aux2 = l2;
  }
}

void ordenaL (tipo_no *l1,tipo_no *l2,tipo_no **l3) {
  tipo_no *aux = l1;
  int contador,N;
  contador = 0;
  N = 0;
  while(aux!=NULL){
    N++;
    aux=aux->prox;
  }
  aux = l2;
  while(aux!=NULL){
    N ++;
    aux = aux->prox;
  }
  int arr[N];
  aux = l1;
  while(aux!=NULL){
    arr[contador] = aux->valor;
    contador++;
    aux= aux->prox;
  }
  aux = l2;
  while(aux!=NULL){
    arr[contador]= aux->valor;
    contador++;
    aux = aux->prox;
  }
  int k,j,l,aux2;
  k=0;
  j=0;
  l = 0;
  for(k=1;k<N;k++){
    for(j=0;j<N-1;j++){
      if(arr[j]> arr[j+1]){
        aux2 = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux2;
      }
    }
  }
  for(l=0;l<N;l++){
    insereFim(l3,arr[l]);
  }
}

void inverteLista(tipo_no **l4,tipo_no *l1){
  int valor;
  while(l1 != NULL){
    valor = removeFim(&l1);
    //insere fim inserindo no inicio
    insereFim(l4, valor);
  }
}

void liberaGeral(tipo_no **lst) {
  tipo_no *aux = *lst;
  while (aux != NULL) { 
    (*lst) = (*lst)->prox;
    free(aux);
    aux = (*lst);
  }
}

void concatena(tipo_no *l1,tipo_no *l2,tipo_no **l3){
  while(l1 != NULL){
    insereFim(l3, l1->valor);
    l1 = l1->prox;
  }
  while(l2!=NULL){
    insereFim(l3,l2->valor);
    l2 = l2->prox;
  }
}



//-------Daqui pra baixo o professor passou em aula--------------
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