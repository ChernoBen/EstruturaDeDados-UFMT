#include <stdio.h>
#include <stdlib.h>

#include "lista.c"
#include "ordenacao.c"
#include "utilidades.c"

//gcc main.c -o main
int main(){
  tipo_lista lista,nova_lista;
  
  inicializaLista(&lista);

  insereFim(&lista,7);
  insereFim(&lista,3);
  insereFim(&lista,9);
  insereFim(&lista,4);
  insereFim(&lista,1);
  insereFim(&lista,5);
  insereFim(&lista,2);
  insereFim(&lista,6);
  imprimeLista(lista);
  //bubble
  //bubbleSort(&lista);
  //shellSort(&lista);
  //lista = insertSort(lista);
  //mergeSort(&lista);
  //quickSort(&lista);
  nova_lista = geraLista(20);
  //bubbleSort(&nova_lista);
  //shellSort(&nova_lista);
  //imprimeLista(insertSort(nova_lista));
  //mergeSort(&nova_lista);
  quickSort(&nova_lista);
  //new_quick_sort(nova_lista.lista,0,nova_lista.contador-1);
  imprimeLista(nova_lista);

  return 1;
}