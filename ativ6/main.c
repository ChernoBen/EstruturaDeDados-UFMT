#include <stdio.h>
#include <stdlib.h>

#include "lista.c"
#include "ordenacao.c"
#include "utilidades.c"
#include "heap.c"

//gcc main.c -o main
int main(){
  tipo_heap heap;
  inicializaHeap(&heap);
  insereHeap(&heap,10);
  insereHeap(&heap,5);
  insereHeap(&heap,15);
  insereHeap(&heap,20);
  insereHeap(&heap,17);
  insereHeap(&heap,8);
  insereHeap(&heap,25);
  imprimeHeap(heap);
  

  return 1;
}