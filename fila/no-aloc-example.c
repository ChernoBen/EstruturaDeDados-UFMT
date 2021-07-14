#include <stdio.h>
#define N 10

struct est_fila{
  int fila[N];
  int contador;
};
typedef struct est_fila tipo_fila;

void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl,int valor);
int removeFila(tipo_fila *fl);
//não executará modificação entao nao precisa de ponteiro
void imprimeFila(tipo_fila fl);

int main(){
  tipo_fila fila;
  fila.contador = 0;
  inicializaFila(&fila);
  insereFila(&fila,6);
  insereFila(&fila,7);
  insereFila(&fila,8);
  insereFila(&fila,9);
  imprimeFila(fila);
  printf("removendo valor %d da fila\n",removeFila(&fila));
  imprimeFila(fila);
  return 1;
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

void insereFila(tipo_fila *fl, int valor){
  if (fl->contador < N){
    fl->fila[fl->contador] = valor;
    fl->contador++;
  }else{
    printf("---[Error] fila estáá cheia---");
  }
}