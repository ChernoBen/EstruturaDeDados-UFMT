#include <stdio.h>
#include <stdlib.h>

#include "lista.c"
#include "ordenacao.c"
#include "utilidades.c"
#include "heap.c"

//gcc main.c -o main
int main(){
  tipo_heap heap,heap2, heapConcatenado;
  tipo_lista lista;
  int entrada = 9;
  // 1# Criar um heap vazio
  inicializaHeap(&heap);
  imprimeHeap(heap);

  // 2# Inserir um novo valor
  insereHeap(&heap,5);
  insereHeap(&heap,4);
  insereHeap(&heap,2);
  imprimeHeap(heap);

  // 3# Consultar valor máximo da Raiz
  printf("Valor maximo da raiz: %d\n",heap.heap[0]);

  // 4# Remover valor máximo do heap
  printf("Valor máximo removido: %d\n",removeHeap(&heap));
  imprimeHeap(heap);

  //Retornar quantidade de valores armazenados no heap
  printf("Qtd valores armazenado no heap: %d\n",heap.cont);

  // 6# Verificar se um dado valor existe dentro do heap
  if(verificaHeap(heap,entrada)==1){
    printf("Valor %d existe dentro do heap\n",entrada);
  }else{
    printf("Valor %d não existe dentro do heap\n",entrada);
  }

  // 7# Unificar dois Heaps em um unico;
  insereHeap(&heap2,9);
  insereHeap(&heap2,1);
  insereHeap(&heap2,7);
  heapConcatenado = concatenarHeap(heap,heap2);
  imprimeHeap(heapConcatenado);
  
  // 8# Ordenar Heaps utilizadno heapSort
  lista = migraHeap(heapConcatenado);
  imprimeLista(lista);
  heapSort(&lista);
  imprimeLista(lista);
  return 1;
}