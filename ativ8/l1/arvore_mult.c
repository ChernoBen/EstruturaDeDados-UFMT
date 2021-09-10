/*
Implementação Arvore Multiplos filhos
*/

#ifndef ARVORE_MULT
#define ARVORE_MULT
#include <stdlib.h>
#include <stdio.h>

#define T 3
//estrutura da arvore
struct est_arv_mf{
    int valores[T];
    struct est_arv_mf *filhos[T+1];
    int contador;
};
typedef struct est_arv_mf tipo_arv_mf;

//prototipos
tipo_arv_mf *alocaNovoNoArvMf(int valor);
void insereArvMf(tipo_arv_mf **arv,int vl);


//funcoes

//aloca novo no
tipo_arv_mf *alocaNovoNoArvMf(int valor){
    int i;
    tipo_arv_mf *novo_no;
    novo_no = (tipo_arv_mf*) malloc(sizeof(tipo_arv_mf));
    novo_no->valores[0] = valor;
    novo_no->contador=1;
    for(i=0;i<T+1;i++){
        novo_no->filhos[i] = NULL;
    }
    return novo_no;
}

//funcao que insere um novo valor na estrutura
void insereArvMf(tipo_arv_mf **arv,int vl){
    if((*arv)==NULL){
        (*arv) = alocaNovoNoArvMf(vl);
    }else{
        //se a arvore menor que T, fazer inserção ordenada
        if((*arv)->contador<T){
            int i;
            i = (*arv)->contador-1;
            while((i>=0)&&((*arv)->valores[i]>vl)){
                (*arv)->valores[i+1] = (*arv)->valores[i];
                i--;    
            }
            (*arv)->valores[i+1]=vl;
            (*arv)->contador++;
        }
    }
}
#endif // !ARVORE_MULT