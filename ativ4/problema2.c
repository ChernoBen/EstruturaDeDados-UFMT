#include <stdio.h>
#define N 10

//FIRST IN FIRST OUT

struct est_fila{
  int fila[N];
  int contador;
  int first;
};
typedef struct est_fila tipo_fila;

void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl,int valor);
int removeFila(tipo_fila *fl);
//não executará modificação entao nao precisa de ponteiro
void imprimeFila(tipo_fila fl);

//proto tasks
void insereFilaN(tipo_fila *fl, int valor);
int removeFilaN(tipo_fila *fl);
void imprimeFilaN(tipo_fila fl);

int main(){
  tipo_fila fila;
  fila.contador = 0;
  fila.first = 0;
  int test;

  /*
  - Vantagem:
    Apenas realiza deslocamentos em adições de novos elementos
    Remoções apenas marcam a partir de qual indice a função de inserção de um novo item \
    pode iniciar o descolcamento.
    Se assim como no clássico se nao ouver inserções não existiram deslocamentos, pois em uma fila\
    novos item são inseridos no final
  */
  
  inicializaFila(&fila);
  insereFila(&fila,6);
  insereFila(&fila,7);
  insereFila(&fila,8);
  insereFila(&fila,9);
  imprimeFila(fila);
  //test
  
  imprimeFila(fila);
  test= removeFilaN(&fila);
  imprimeFilaN(fila);
  test= removeFilaN(&fila);
  imprimeFilaN(fila);
  test= removeFilaN(&fila);
  imprimeFilaN(fila);
  test= removeFilaN(&fila);
  imprimeFilaN(fila);
  test= removeFilaN(&fila);

  insereFilaN(&fila, 1);
  imprimeFilaN(fila);
  insereFilaN(&fila, 2);
  imprimeFilaN(fila);
  insereFilaN(&fila, 3);
  imprimeFilaN(fila);

  return 1;
}



void imprimeFila(tipo_fila fl){
  int i;
  printf("[");
  for (i=0;i<fl.contador;i++){
    printf("%d ",fl.fila[i]);
  }
  printf("]\n");
}

void inicializaFila(tipo_fila *fl){
  fl->contador = 0;
}

int removeFila(tipo_fila *fl){
  if(fl->contador > 0){
    int aux;
    aux = fl->fila[0];
    //atualiza as posições no vetor
    for(int i=0;i<fl->contador-1;i++){
      fl->fila[i] = fl->fila[i+1];
    }
    fl->contador--;
    return aux;
  }else{
    printf("[error] fila vazia");
    return -1;
  }
}

void insereFila(tipo_fila *fl, int valor){
  if (fl->contador < N){
    fl->fila[fl->contador] = valor;
    fl->contador++;
  }else{
    printf("---[Error] fila estáá cheia---");
  }
}

//task

int removeFilaN(tipo_fila *fl){
  if(fl->contador > 0){
    int aux;
    aux = fl->fila[0];
    //atualiza as posições no vetor
    // for(int i=0;i<fl->contador-1;i++){
    //   fl->fila[i] = fl->fila[i+1];
    // }
    fl->first += 1;
    fl->contador--;
    return aux;
  }else{
    printf("[error] fila vazia\n");
    return -1;
  }
}

void insereFilaN(tipo_fila *fl, int valor){
  if (fl->contador < N){
    //se aconteceu qualquer remoção entao desloque
    if(fl->first >=1){
      for(int i=0;i<fl->contador-1;i++){
        fl->fila[i] = fl->fila[i+1];
      }
      fl->first=0;
    }
    fl->fila[fl->contador] = valor;
    fl->contador++;
  }else{
    printf("---[Error] fila está cheia---");
  }
}

void imprimeFilaN(tipo_fila fl){
  int i;
  printf("[");
  if(fl.first>=1){
    i = 1;
  }
  for (i=0;i<fl.contador;i++){
    printf("%d ",fl.fila[i]);
  }
  printf("]\n");
}
