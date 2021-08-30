#include <stdio.h>
#include <stdlib.h>

#include "lista.c"
#include "ordenacao.c"
#include "utilidades.c"
#include "heap.c"

//gcc main.c -o main
int main(){
  tipo_heap heap;
  tipo_lista lista;
  /*
  inicializaHeap(&heap);
  insereHeap(&heap,10);
  insereHeap(&heap,5);
  insereHeap(&heap,15);
  insereHeap(&heap,20);
  insereHeap(&heap,17);
  insereHeap(&heap,8);
  insereHeap(&heap,25);
  imprimeHeap(heap);

  printf("Valor removido:%d\n",removeHeap(&heap));
  printf("Segundo maior Valor removido:%d\n",removeHeap(&heap));
  printf("Terceiro maior Valor removido:%d\n",removeHeap(&heap));
  printf("Quarto maior Valor removido:%d\n",removeHeap(&heap));
  printf("Quinto maior Valor removido:%d\n",removeHeap(&heap));
  printf("Sexto maior Valor removido:%d\n",removeHeap(&heap));
  */
  inicializaLista(&lista);
  insereFim(&lista,10);
  insereFim(&lista,1);
  insereFim(&lista,7);
  insereFim(&lista,4);
  insereFim(&lista,8);
  insereFim(&lista,3);
  insereFim(&lista,6);
  imprimeLista(lista);
  heapSort(&lista);
  imprimeLista(lista);

  return 1;
}