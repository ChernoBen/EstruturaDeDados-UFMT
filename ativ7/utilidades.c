#ifndef UTILIDADES_C
#define UTILIDADES_C

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.c"
#include "heap.c"

//prototipos
tipo_lista geraLista(int qtd);
tipo_heap concatenarHeap(tipo_heap hp1,tipo_heap hp2);
int verificaHeap(tipo_heap hp,int valor);
tipo_lista migraHeap(tipo_heap hp);

//funcao que gera lista aleatoria
tipo_lista geraLista(int qtd){
    int i,val; 
    tipo_lista lista;
    inicializaLista(&lista);

    for (i=0;i<qtd+1;i++){
        //gera numeros inteiros de 0-9
        val = (rand()%10);
        insereFim(&lista,val);
    }
    return lista;
}

//funcao que verifica se um valor está presente no heap
int verificaHeap(tipo_heap hp,int valor){
    tipo_heap heapCopia;
    heapCopia = hp;
    int i,item;
    for (i=0;i<hp.cont;i++){
        item = removeHeap(&heapCopia);
        if(item == valor){
            return 1;
        }
    }
    return 0;
}

//funcao que contatena 2 heap´s
tipo_heap concatenarHeap(tipo_heap hp1,tipo_heap hp2){
    tipo_heap concatenado;
    inicializaHeap(&concatenado);
    int i;
    for(i=0;i<hp1.cont;i++){
        insereHeap(&concatenado,hp1.heap[i]);
    }
    for(i=0;i<hp2.cont;i++){
        insereHeap(&concatenado,hp2.heap[i]);
    }
    return concatenado;
}

//funcao que recebe um tipo heap e retorna uma lista
tipo_lista migraHeap(tipo_heap hp){
    tipo_lista lista;
    inicializaLista(&lista);
    int i;
    for(i=0;i<hp.cont;i++){
        insereFim(&lista,hp.heap[i]);
    }
    return lista;
}

#endif