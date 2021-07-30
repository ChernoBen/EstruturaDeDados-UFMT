#include <stdio.h>
#define N 10
#define M 20


struct est_lista{
  int lista[N];
  int contador;
};

//estrutura da nova lista/ possui o dobro do valor da l1
typedef struct est_lista tipo_lista;
struct nova_lista{
  int lista[M];
  int contador;
};
typedef struct nova_lista nl;

void inicializaLista(tipo_lista *ls);
void insereFim(tipo_lista *ls, int valor);
void insereInicio(tipo_lista *ls,int valor);
void inserePosicao(tipo_lista *ls, int valor, int posicao);
void imprimeLista(tipo_lista ls);
int removeFim(tipo_lista *ls);
int removeInicio(tipo_lista *ls);
int removePosicao(tipo_lista *ls, int posicao);

//---------prototipos das funções para manipular a nova lista gerada----------------------------------------------

void inicializaL(nl *novaL);
void insereFimNl(nl *novaL, int valor);
int removeInicioNl(nl *novaL);
nl concatena(tipo_lista l1,tipo_lista l2);
void imprimeListaNl(nl novaL);
nl ordenaL(nl novaL);
nl decrescente(nl novaL);

//função principal
int main(){
  
  //inicialização da l1 e l2 para poder concatenar e gerar uma nova lista
  tipo_lista l1,l2;
  inicializaLista(&l1);
  insereFim(&l1, 1);
  insereFim(&l1, 4);
  insereFim(&l1, 9);
  inicializaLista(&l2);
  insereFim(&l2, 7);
  insereFim(&l2, 8);
  insereFim(&l2, 10);
  imprimeLista(l1);
  imprimeLista(l2);

  //inicializando e manipulando lista concatenada
  nl concatenada;
  inicializaL(&concatenada);
  //inicializando lista que recebera a lista concatenada não organizada
  nl conca;
  conca = concatena(l1,l2);
  imprimeListaNl(conca);
  //inicialização da lista que recebe a lista ordenada descrescente
  nl orderedConca;
  orderedConca = ordenaL(conca);
  imprimeListaNl(orderedConca);
  
  return 1;
}

//----funções necessarias para gerar a nova lista ordenada

nl ordenaL (nl novaL) {
  int k, j, aux;
  nl nova;
  inicializaL(&nova);
  int total = novaL.contador;
  for (k = 1; k < novaL.contador; k++) {
    for (j = 0; j < novaL.contador - 1; j++) {
      if (novaL.lista[j] > novaL.lista[j + 1]) {
        aux = novaL.lista[j];
        novaL.lista[j] = novaL.lista[j + 1];
        novaL.lista[j + 1] = aux;
      }
    }
  }
  for(int i=novaL.contador-1;i>=0;i--){
    insereFimNl(&nova, novaL.lista[i]);
  }
  return nova;
}

nl concatena(tipo_lista l1,tipo_lista l2){
  nl lConcatenada;
  inicializaL(&lConcatenada);
  for(int i=l2.contador-1;i>=0; i--){
    insereFimNl(&lConcatenada, l2.lista[i]);
  }
  for(int i=l1.contador-1;i>=0;i--){
    insereFimNl(&lConcatenada, l1.lista[i]);
  }
  return lConcatenada;
}

void imprimeListaNl(nl novaL){
  printf("lista [");
  int i;
  for (i=0;i<novaL.contador;i++){
    printf(" %d ",novaL.lista[i]);
  }
  printf("]\n");
}

void inicializaL(nl *novaL){
  novaL->contador = 0;
}

void insereFimNl(nl *novaL, int valor){
  if(novaL->contador < N){
    novaL->lista[novaL->contador++] = valor;
  }else{
    printf("[error] lista cheia\n");
  }
}


//-----------------------funções que o ivairton passou nas aulas,
//-----------------------necessarias para gerar lista1(l1) e l2
int removeInicioNl(nl *novaL){
  if(novaL->contador > 0 ){
    int aux,i;
    aux = novaL->lista[0];
    for (i=0;i<novaL->contador-1;i++){
      novaL->lista[i] = novaL->lista[i+1];
    }
    novaL->contador--;
    return aux;
  }else{
    printf("[erro] lista vazia\n");
    return -1;
  }
}


//-------------------------------------
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

//passar na farmacia pegar 1-cx neosaldina
//passar na loterica conferir resultado da quina 