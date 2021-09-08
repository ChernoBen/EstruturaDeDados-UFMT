/*
Implementação Arvore Binária
*/

#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA
#include <stdlib.h>
#include <stdio.h>

//definição estrutura encadeada do nó da arvore binaria
struct est_arv_bin{
    struct est_arv_bin *esq;
    struct est_arv_bin *dir;
    int valor;
};
typedef struct est_arv_bin tipo_arv_bin;

//Prototipos
tipo_arv_bin *alocaNovoNo(int valor);
void insereArvBin(tipo_arv_bin  **arv,int valor);


//funcao que aloca novo nó da arvore binaria
tipo_arv_bin *alocaNovoNo(int valor){
    tipo_arv_bin *novo_no;
    novo_no = (tipo_arv_bin*) malloc(sizeof(tipo_arv_bin));
    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

//funcao que insere um valor na arvore binária
void insereArvBin(tipo_arv_bin **arv,int valor){
    //se arv é null, alocar um no
    if ((*arv) == NULL){
        (*arv) = alocaNovoNo(valor);
    }else{
        //verificar se o valor é menor que o nó
        if (valor < (*arv)->valor){
            insereArvBin(&(*arv)->esq,valor);
        }else{
            //se maior insira na posição esq
            insereArvBin(&(*arv)->dir,valor);
        }
    }
}

#endif // !ARVORE_BINARIA