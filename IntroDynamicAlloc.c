#include <stdio.h>
#include <stdlib.h>

struct estru_no{
  int valor;//espaco para guardar valor
  struct estru_no *prox;//guarda endereco para outra estrutura
};
typedef struct estru_no tipo_no;

int main(){
  tipo_no *fila;
  fila = NULL;

  //ponteiro tipo tipo_nó declarado
  tipo_no *novo_no;
  //alocação de memoria tipo_no(um espaco na memoria é criado para uma estrutura tipo_no)
  novo_no = (tipo_no*) malloc(sizeof(tipo_no));
  //Inicialização dos campos
  novo_no->valor = 10;
  novo_no->prox=NULL;//este campo recebe o endereço para a proxima estrutura
  fila = novo_no;

  novo_no = (tipo_no*) malloc(sizeof(tipo_no));
  novo_no->valor=3;
  novo_no->prox=NULL;
  /*- A diferença é que agora a estrutura fila que já está declarada ira guardar um novo nó em prox
  */
  fila->prox =  novo_no;
  /*
    visualmente:
    estrutura {
      chave:valor,
      segundaEstrutura:{
        chave:valor,
        terceiraEstrutura:NULL
      }
    }
  */
  printf("valor=%d\n",fila->valor);
  printf("valor=%d\n",fila->prox->valor);

  return 1;
}