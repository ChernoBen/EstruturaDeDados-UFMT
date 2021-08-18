#ifndef HEAP_C
#define HEAP_C


#include <stdio.h>
#include <stdlib.h>

#define M 20
struct heap_est{
    int heap[M];
    int cont;
};
typedef struct heap_est tipo_heap;

//prototipos

int posPai(int);
int posFEsq(int);
int posFDir(int);
void inicializaHeap(tipo_heap *hp);
void insereHeap(tipo_heap *hp,int valor);
void sobeValor(tipo_heap *hp,int pos);
void imprimeHeap(tipo_heap hp);

//funcoes
void inicializaHeap(tipo_heap *hp){
    hp->cont =0;

}

//funcao que insere novo valor no heap
void insereHeap(tipo_heap *hp,int valor){
    hp->heap[hp->cont++] = valor;
    sobeValor(hp,hp->cont-1);

}

//F para heap maximo
void sobeValor(tipo_heap *hp,int pos){
    int aux;
    if(hp->heap[pos] > hp->heap[posPai(pos)]){
        aux = hp->heap[pos];
        hp->heap[pos] = hp->heap[posPai(pos)];
        hp->heap[posPai(pos)] = aux;
        if(posPai(pos)>0){
            //se nao alcancou a raiz
            sobeValor(hp,posPai(pos));
        }
    }
}

//funcoes que calculam posicoes pais/filhos(esquerdo/direito)
int posPai(int i ){
    //Posicao pai = vetor[(i-1)/2]
    //forcar retorno de inteiro
    return ((int)(i-1)/2);
}

int posFEsq(int i){
    //Posicao filho esquerdo = vetor[(2*i)+1]
    return (2*i)+1;
}

int posFDir(int i){
    //Posicao filho direito = vetor[(2*i)+1]
    return (2*i)+2;
}

void imprimeHeap(tipo_heap hp){
    int i;
    printf("HEAP MAX [");
    for (i=0;i<hp.cont;i++){
        printf("%d ",hp.heap[i]);
    }
    printf("]\n");
}

#endif