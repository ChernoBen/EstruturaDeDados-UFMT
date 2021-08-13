#include <stdio.h>
#include <stdlib.h>

#include "lista.c"
#include "ordenacao.c"
#include "utilidades.c"

//gcc main.c -o main
int main(){
  //quantidade
  int qtd = 10000;
  tipo_lista lista,shell_lst,bubble_lst,insert_lst,merge_lst,quick_lst;
  
  lista = geraLista(qtd);
  bubble_lst = lista;
  shell_lst = lista;
  insert_lst = lista;
  merge_lst = lista;
  quick_lst = lista;
  
  //bubble
  bubbleSort(&bubble_lst);
  //shell
  shellSort(&shell_lst);
  //insert
  insert_lst = insertSort(insert_lst);
  //merge
  mergeSort(&merge_lst);
  //quick
  quickSort(&quick_lst);
  

  return 1;
}