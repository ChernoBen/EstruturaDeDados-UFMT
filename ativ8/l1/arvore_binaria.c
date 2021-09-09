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
void percursoPreOrdem(tipo_arv_bin *arv);
void percursoPosOrdem(tipo_arv_bin *arv);
void percursoOrdem(tipo_arv_bin *arv);
void imprimirNiveis(tipo_arv_bin *arv);
int contaBilizaBin(tipo_arv_bin *arv);
int obterAlturaArv(tipo_arv_bin *arv);
int buscaValor(tipo_arv_bin *arv,int vl);
tipo_arv_bin *removeValor(tipo_arv_bin *arv, int vl);
void imprimeFolhas(tipo_arv_bin *arv);

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

//implementação do percurso pré ordem
void percursoPreOrdem(tipo_arv_bin *arv){
    if(arv !=NULL){
        //1# imprimir
        printf("%d ",arv->valor);
        percursoPreOrdem(arv->esq);
        percursoPreOrdem(arv->dir);
    }
}

//implementação percurso pós ordem
void percursoPosOrdem(tipo_arv_bin *arv){
    if(arv != NULL){
        percursoPosOrdem(arv->esq);
        percursoPosOrdem(arv->dir);
        printf("%d ", arv->valor);
    }
}

//implementação percurso em ordem
void percursoOrdem(tipo_arv_bin *arv){
    if(arv!=NULL){
        percursoOrdem(arv->esq);
        printf("%d ", arv->valor);
        percursoOrdem(arv->dir);
    }
}

//funcao que imprime valores por nivel


//func que contabiliza quantidade de itens na arv
int contaBilizaBin(tipo_arv_bin *arv){
    if(arv == NULL){
        return 0;
    }else{
        return contaBilizaBin(arv->esq)+contaBilizaBin(arv->dir)+1;
    }
}

//funcao que retorna a altura da arvore binaria
int obterAlturaArv(tipo_arv_bin *arv){
    int altura = contaBilizaBin(arv);
    if(altura>1){
        return altura/2;
    }
    return 0;
}

//funcao que busca um valor na arvore binaria
int buscaValor(tipo_arv_bin *arv,int vl){
    if(arv == NULL || arv->valor==vl){
        if(arv == NULL){
            return -1;
        }else{
            return arv->valor;
        }
    }
    if(arv->valor > vl){
        return buscaValor(arv->esq,vl);
    }else{
        return buscaValor(arv->dir,vl);
    }
}

//remover valor definido pelo usuario
tipo_arv_bin *removeValor(tipo_arv_bin *arv, int vl){
    if(arv == NULL){
        return NULL;
    }else if(arv->valor > vl){
        arv->esq = removeValor(arv->esq,vl);
    }else if(arv->valor < vl){
        arv->dir = removeValor(arv->dir,vl);
    }
    if(arv->esq == NULL && arv->dir == NULL){
        free(arv);
        arv = NULL;
    }else if(arv->esq == NULL){
        tipo_arv_bin *aux  = arv;
        arv = arv->dir;
        free(aux);
    }else if(arv->dir == NULL){
        tipo_arv_bin *aux2 = arv;
        arv = arv->esq;
        free(aux2);
    }else{
        tipo_arv_bin *nova_arv = arv->esq;
        while(nova_arv->dir != NULL){
            nova_arv = nova_arv->dir;
        }
        arv->valor = nova_arv->valor;
        nova_arv->valor = vl;
        arv->esq = removeValor(arv->esq,vl);
    }
    return arv;
}
//função que imprime folhas
void imprimeFolhas(tipo_arv_bin *arv){
    if(arv==NULL){
        printf("");
    }else{
        if(arv->esq == NULL && arv->dir == NULL){
            printf("%d ",arv->valor);
        }else{
            imprimeFolhas(arv->esq);
            imprimeFolhas(arv->dir);
        }
    }
}

//funcao que imprime niveis da arbore binaria
void imprimirNiveis(tipo_arv_bin *arv){
    //printf("\n");
    if(arv!=NULL) {
        
        if(arv->dir!=NULL) { 
            printf("%d  ",arv->dir->valor);
            imprimirNiveis(arv->dir);
        }
        
        if(arv->esq!=NULL) { 
            printf("%d  ",arv->esq->valor);
            imprimirNiveis(arv->esq);
        }
        
    }
}
#endif // !ARVORE_BINARIA