#ifndef HEAP_C
#define HEAP_C


#include <stdio.h>
#include <stdlib.h>

#define M 30
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
int removeHeap(tipo_heap *hp);
void desceValor(tipo_heap *hp,int pos);
//funcoes
void inicializaHeap(tipo_heap *hp){
    hp->cont =0;

}

//funcao que insere novo valor no heap
void insereHeap(tipo_heap *hp,int valor){
    hp->heap[hp->cont++] = valor;
    sobeValor(hp,hp->cont-1);

}

//função que remove um elemento da raiz
int removeHeap(tipo_heap *hp){
    //var que irá guardar valor que esta na raiz
    int valor;
    //verifica se existe algum valor no heap
    if (hp->cont>0){
        //guarda valor da raiz para retornar no final da execução da funcao
        valor= hp->heap[0];
        //guardar o ultimo elemento na posição da raiz
        hp->heap[0] = hp->heap[--hp->cont];
        //função que ordena valores apos remoção da raiz
        desceValor(hp,0);
        return valor;
    }else{
        return -1;
    }
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

//Funcao que desce valor até pos adequada
void desceValor(tipo_heap *hp,int pos){
    int novaPos,aux;
    novaPos = -1;
    //verificar se as posições esq e dir são validas
    if(posFEsq(pos)<hp->cont){
        if(posFDir(pos)<hp->cont){
            //se filho esquerdo maior que filho direito
            if(hp->heap[posFEsq(pos)]>hp->heap[posFDir(pos)]){
                if(hp->heap[pos]<hp->heap[posFEsq(pos)]){
                   novaPos=posFEsq(pos); 
                }
            }else{
                if(hp->heap[pos]<hp->heap[posFDir(pos)]){
                    novaPos=posFDir(pos);
                }
            }
        }else{
            if(hp->heap[pos] < hp->heap[posFEsq(pos)]){
                novaPos=posFEsq(pos);
            }
        }
        //verificar se fazer trocas ou não
        if (novaPos > -1){
            aux = hp->heap[pos];
            hp->heap[pos] = hp->heap[novaPos];
            hp->heap[novaPos]=aux;
            //chamada recursiva
            desceValor(hp,novaPos);
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